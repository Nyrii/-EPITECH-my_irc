/*
** join.c for join in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 17:43:49 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 21:13:51 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

t_list		*createFirstChannel(char *command, t_list *newUser)
{
  t_udata	*udata;
  t_cdata	*cdata;
  t_list	*channel;

  if ((cdata = malloc(sizeof(t_cdata))) == NULL)
    return (puterr(ERR_MALLOC, NULL));
  udata = ((t_udata *)newUser->struc);
  if (udata->current_channel != NULL)
    free(udata->current_channel);
  if ((udata->current_channel = strdup(command)) == NULL)
    return (puterr(ERR_STRDUP, NULL));
  if ((cdata->users = create_list(udata, NULL)) == NULL)
    return (NULL);
  if ((cdata->name = strdup(command)) == NULL)
    return (puterr(ERR_STRDUP, NULL));
  if ((channel = create_list(cdata, NULL)) == NULL)
    return (NULL);
  return (channel);
}

int		addUserToChannel(const int fd, t_list *newUser,
				 t_list *current_channel)
{
  t_udata	*udata;

  udata = ((t_udata *)newUser->struc);
  if (udata->current_channel != NULL)
    free(udata->current_channel);
  udata->current_channel = strdup(((t_cdata *)(current_channel->struc))->name);
  if (udata->current_channel == NULL)
    return (puterr_int(ERR_STRDUP, -1));
  if (!((t_cdata *)(current_channel->struc))->users)
    {
      ((t_cdata *)(current_channel->struc))->users = create_list(udata, NULL);
      if (!((t_cdata *)(current_channel->struc))->users)
	return (-1);
    }
  else if (((t_cdata *)(current_channel->struc))->users->push_back
	   (((t_cdata *)(current_channel->struc))->users, udata) == NULL)
    return (puterr_int("Error: push back of users failed.\n", -1));
  return (joinSucceed(fd, current_channel));
}

int		addNewChannel(const int fd, char *command,
			      t_list *newUser, t_list **channel)
{
  t_cdata	*cdata;
  t_udata	*udata;

  if ((cdata = malloc(sizeof(t_cdata))) == NULL)
    return (puterr_int(ERR_MALLOC, -1));
  udata = ((t_udata *)newUser->struc);
  if (udata->current_channel != NULL)
    free(udata->current_channel);
  if ((udata->current_channel = strdup(command)) == NULL)
    return (puterr_int(ERR_STRDUP, -1));
  if ((cdata->users = create_list(udata, NULL)) == NULL)
    return (-1);
  if ((cdata->name = strdup(command)) == NULL)
    return (puterr_int(ERR_STRDUP, -1));
  if (((*channel)->push_back(*channel, cdata)) == NULL)
    return (puterr_int(ERR_PUSHBACKCHANNEL, -1));
  return (joinSucceed(fd, *(*channel)->last));
}

int		editChannels(const int fd, char *command,
			   t_list **channel, t_list *users)
{
  t_list	*tmp;
  t_list	*newUser;

  if ((newUser = getUser(users, fd)) == NULL)
    return (puterr_int(ERR_UNKNOWNUSER, -1));
  if (*channel == NULL)
    {
      if ((*channel = createFirstChannel(command, newUser)) == NULL)
	return (-1);
      return (joinSucceed(fd, *channel));
    }
  else if ((tmp = searchChannelByName(*channel, command)) != NULL
	   && searchChannelByUserFd(tmp, fd) == -1)
    return (addUserToChannel(fd, newUser, tmp));
  else if (*channel != NULL
	   && (tmp = searchChannelByName(*channel, command)) == NULL)
    return (addNewChannel(fd, command, newUser, channel));
  return (alreadyInChannel(fd, searchChannelByName(*channel, command)));
}

int		join(const int fd, char *command,
		     t_list **channel, t_list **users)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_NEEDMOREPARAMS,
	       getUserName(*users, fd), "JOIN") == -1)
    return (puterr_int("Error: snprintf failed.\n", -1));
  if (command == NULL)
    return (answerClient(fd, buffer, -2));
  if (command && command[0] != '#')
    {
      if (memset(buffer, 0, 4096) == NULL)
	return (puterr_int(ERR_MEMSET, -1));
      if (snprintf(buffer, 4096, ERR_NOSUCHCHANNEL, command) == -1)
	return (puterr_int("Error: snprintf failed.\n", -1));
      return (answerClient(fd, buffer, -2));
    }
  if (editChannels(fd, command, channel, *users) == -1)
    return (-1);
  return (0);
}
