/*
** join_messages.c for join_messages in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 21:16:56 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 02:17:13 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

int		join_succeed(const int fd, t_list *current_channel)
{
  char		buffer[4096];
  t_list	*tmp;
  char		*username;

  if ((username = get_user_name(((t_cdata *)(current_channel->struc))->users,
			      fd)) == NULL)
    return (puterr_int(ERR_INTERNALJOIN, -1));
  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, RPL_JOINOK, username,
	       ((t_cdata *)(current_channel->struc))->name) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  tmp = ((t_cdata *)(current_channel->struc))->users;
  while (tmp != NULL)
    {
      if (answer_client(((t_udata *)(tmp->struc))->fd, buffer, 0) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int		already_in_channel(const int fd, t_list *current_channel)
{
  char		buffer[4096];
  char		*channel_name;
  char		*username;

  if (current_channel == NULL)
    return (puterr_int(ERR_INTERNALJOIN, -1));
  channel_name = ((t_cdata *)(current_channel->struc))->name;
  username = get_user_name(((t_cdata *)(current_channel->struc))->users, fd);
  if (channel_name == NULL || username == NULL)
    return (puterr_int(ERR_INTERNALJOIN, -1));
  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_USERONCHANNEL, username, channel_name) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  return (answer_client(fd, buffer, 0));
}
