/*
** msg.c for msg in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 17:44:45 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 23:33:14 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

void		store_message(char **message, char *username,
			      char *to_send)
{
  int		i;
  int		len;

  i = 0;
  len = strlen((*message));
  while (username[i])
    (*message)[len++] = username[i++];
  i = 0;
  (*message)[len++] = ' ';
  (*message)[len++] = ':';
  while (to_send[i])
    (*message)[len++] = to_send[i++];
  (*message)[len++] = '\r';
  (*message)[len++] = '\n';
  (*message)[len] = '\0';
}

char		*get_message(char *username, char *to_send, int is_private)
{
  char		*message;

  if (!username || !to_send)
    return (puterr(ERR_INTERNALMSG, NULL));
  if ((message = strdup(!is_private ? RPL_MSG : RPL_PRIVMSG)) == NULL)
    return (puterr(ERR_STRDUP, NULL));
  if ((message = realloc(message,
			 20 + strlen(to_send) + strlen(username))) == NULL)
    return (puterr(ERR_REALLOC, NULL));
  store_message(&message, username, to_send);
  return (message);
}

int		send_msg_to_channel(const int fd, char **args, t_list **users,
				    t_list **channels)
{
  t_list	*tchannel;
  t_list	*user;
  char		*message;

  if (!(tchannel = search_channel_by_name(*channels, args[0])))
    no_such_channel(get_user(*users, fd), args[0]);
  if (!tchannel->struc || !(user = ((t_cdata *)(tchannel->struc))->users))
    return (puterr_int(ERR_UNKNOWNUSER, -1));
  if (get_index_user_from_users_list(user, fd) == -1)
    cannot_send_to_chan(get_user(*users, fd), args[0]);
  if ((message = get_message(get_user_name(*users, fd), args[1], 0)) == NULL)
    return (-1);
  while (user != NULL)
    {
      if (store_answer(user, message, 0) == -1)
	return (-1);
      user = user->next;
    }
  free(message);
  return (0);
}

int		send_msg_to_user(const int fd, char **args, t_list **users)
{

  t_list	*user;
  char		buffer[4096];
  char		*message;

  if (!(user = get_user_by_name(*users, args[0])))
    {
      if (memset(buffer, 0, 4096) == NULL)
	return (puterr_int(ERR_MEMSET, -1));
      if (snprintf(buffer, 4096, ERR_NOSUCHNICK, args[0]) == -1)
		return (puterr_int(ERR_SNPRINTF, -1));
      return (store_answer(get_user(*users, fd), buffer, -2));
    }
  if ((message = get_message(((t_udata *)(user->struc))->name,
			     args[1], 1)) == NULL)
    return (-1);
  if (store_answer(user, message, 0) == -1)
    return (-1);
  free(message);
  return (0);
}

int		msg(const int fd, char *command,
		    t_list **channels, t_list **users)
{
  char		*args[3];

  args[0] = NULL;
  args[1] = NULL;
  args[2] = NULL;
  if (take_two_args(args, command) == -1 && args[0])
    return (not_enough_params(get_user(*users, fd), "MSG"));
  else if (!args[1])
    return (store_answer(get_user(*users, fd), ERR_NOTEXTTOSEND, -2));
  if (args[0] && args[0][0] == '#')
    return (send_msg_to_channel(fd, args, users, channels));
  return (send_msg_to_user(fd, args, users));
}
