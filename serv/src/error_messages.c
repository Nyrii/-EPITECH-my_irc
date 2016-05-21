/*
** error_messages.c for error_messages.c in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Sat May 21 14:43:25 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 14:49:04 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <stdio.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

int		not_enough_params(const int fd, t_list *users,
				  const char *command)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_NEEDMOREPARAMS,
	       get_user_name(users, fd), command) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  return (answer_client(fd, buffer, -2));
}
