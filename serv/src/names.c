/*
** names.c for names in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Fri May 20 21:36:28 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 23:06:15 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

int		names(const int fd, char *command,
		      t_list **channel, t_list **users)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_NEEDMOREPARAMS,
	      getUserName(*users, fd), "NAMES") == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  if (command == NULL)
    return (answerClient(fd, buffer, -2));

  t_list	*current_channel;

  if ((current_channel = searchChannelByName(*channel, command)) == NULL)
    {
      if (memset(buffer, 0, 4096) == NULL)
	return (puterr_int(ERR_MEMSET, -1));
      if (snprintf(buffer, 4096, ERR_NOSUCHNICK, command) == -1)
	return (puterr_int(ERR_SNPRINTF, -1));
      return (answerClient(fd, buffer, -2));
    }

  t_list	*tmp_users;
  char		*names_list;
  char		*name;
  int		len;

  len = 0;
  names_list = NULL;
  tmp_users = ((t_cdata *)(current_channel->struc))->users;
  while (tmp_users != NULL)
    {
      name = ((t_udata *)(tmp_users->struc))->name;
      if (len == 0)
	{
	  if ((names_list = malloc(strlen(name) + 2)) == NULL)
	    return (puterr_int(ERR_MALLOC, -1));
	  names_list[0] = '\0';
	}
      else if ((names_list = realloc(names_list,
				     len + strlen(name) + 2)) == NULL)
	return (puterr_int(ERR_REALLOC, -1));
      if (len != 0)
	{
	  names_list[len++] = ' ';
	  names_list[len++] = '\0';
	}
      if ((names_list = strcat(names_list, name)) == NULL)
	return (puterr_int(ERR_STRCAT, -1));
      len += strlen(name);
      tmp_users = tmp_users->next;
    }

  char		*answer;

  answer = NULL;
  if ((answer = malloc(50 + len)) == NULL)
    return (puterr_int(ERR_MALLOC, -1));
  if (snprintf(answer,
	       50 + len,
	       RPL_NAMREPLAY, ((t_cdata *)(current_channel->struc))->name,
	       len != 0 ? names_list : "\0") == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  if (answerClient(fd, answer, 0) == -1)
    return (puterr_int(ERR_COMMUNICATE, -1));
  free(names_list);
  free(answer);
  // 366
  return (0);
}
