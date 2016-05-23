/*
** user.c for user in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Sun May 22 16:47:22 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 23 14:40:20 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

int		user(const int fd, char *command,
		     UNUSED t_list **channels, t_list **users)
{
  t_list	*user;
  char		*args[5];
  t_udata	*data;

  if ((user = get_user(*users, fd)) == NULL
      || (data = (t_udata *)(user->struc)) == NULL)
    return (puterr_int(ERR_UNKNOWNUSER, -1));
  if (((t_udata *)(user->struc))->is_registered == 1)
    return (store_answer(user, ERR_ALREADYREGISTERED, -2));
  if (take_args(args, command, 4) == -1)
    return (not_enough_params(get_user(*users, fd), "USER"));
  if (!(data->uname = strdup(args[0]))
      || !(data->host = strdup(args[1]))
      || !(data->serv = strdup(args[2]))
      || !(data->rname = strdup(args[3])))
    return (puterr_int(ERR_STRDUP, -1));
  data->is_registered = 1;
  store_answer(user, RPL_AUTHENTIFIED, 0);
  return (0);
}
