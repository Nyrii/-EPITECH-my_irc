/*
** join.c for join in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 17:43:49 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 22:35:33 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

t_list		*createFirstChannel(const int fd, char *command, t_list *users)
{
  t_udata	*udata;
  t_cdata	*cdata;
  t_list	*newUser;
  t_list	*channel;

  if ((newUser = getUser(users, fd)) == NULL)
    return (puterr(ERR_UNKNOWNUSER, NULL));
  if ((cdata = malloc(sizeof(t_cdata))) == NULL)
    return (puterr(ERR_MALLOC, NULL));
  udata = ((t_udata *)newUser->struc);
  if ((cdata->users = create_list(udata, NULL)) == NULL)
    return (NULL);
  cdata->name = command;
  if ((channel = create_list(cdata, NULL)) == NULL)
    return (NULL);
  return (channel);
}

int		addUserToChannel(const int fd, t_list *users,
				 t_list *current_channel)
{
  t_list	*newUser;
  t_udata	*udata;

  if ((newUser = getUser(users, fd)) == NULL)
    return (puterr_int(ERR_UNKNOWNUSER, -1));
  if ((udata = malloc(sizeof(t_udata))) == NULL)
    return (puterr_int(ERR_MALLOC, -1));
  ((t_udata *)(newUser->struc))->current_channel =
      ((t_cdata *)(current_channel->struc))->name;
  udata = ((t_udata *)newUser->struc);
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

int		editChannels(const int fd, char *command,
			   t_list **channel, t_list *users)
{
  t_list	*tmp;

  if (*channel == NULL)
    {
      if ((*channel = createFirstChannel(fd, command, users)) == NULL)
	return (-1);
      return (joinSucceed(fd, *channel));
    }
  else if ((tmp = searchChannelByName(*channel, command)) != NULL
	   && searchChannelByUserFd(tmp, fd) == -1)
    return (addUserToChannel(fd, users, tmp));
  else if (*channel != NULL
	   && (tmp = searchChannelByName(*channel, command)) == NULL)
    {
      return (0);
    }
  return (alreadyInChannel(fd, searchChannelByName(*channel, command)));
}

int		join(const int fd, char *command,
		     t_list **channel, t_list *users)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_NEEDMOREPARAMS,
	       getUserName(users, fd), "JOIN") == -1)
    return (puterr_int("Error: snprintf failed.\n", -1));
  if (command == NULL)
    return (answerClient(fd, buffer, -2));
  if (editChannels(fd, command, channel, users) == -1)
    return (-1);
  saveChannels(*channel);

  /**/
  t_list *tmp;
  t_list *userchannel;
  tmp = *channel;
  while (tmp)
    {
      userchannel = ((t_cdata *)((tmp)->struc))->users;
      printf("channel name = %s\n", ((t_cdata *)((tmp)->struc))->name);
      while (userchannel != NULL)
	{
	  printf("user name = %s\n", ((t_udata *)(userchannel->struc))->name);
	  userchannel = userchannel->next;
	}
      tmp = tmp->next;
    }
  /**/
  return (0);
}
