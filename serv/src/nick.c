/*
** nick.c for nick in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 17:45:44 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 22:23:39 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

int		already_in_use(const int fd, const char *command)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_NICKNAMEINUSE, command) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  return (answer_client(fd, buffer, -2));
}

int		erroneus_nickname(const int fd, const char *command)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_ERRONEUSNICKNAME, command) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  return (answer_client(fd, buffer, -2));
}

int		check_new_name(const int fd, const char *name)
{
  int		i;

  i = -1;
  while (name[++i])
    {
      if ((i == 0 && !isalpha(name[i]))
	  || (i != 0 && (!isalnum(name[i])
			 && name[i] != '-' && name[i] != '['
			 && name[i] != ']' && name[i] != '\\'
			 && name[i] != '`' && name[i] != '^'
			 && name[i] != '{' && name[i] != '}')))
      return (erroneus_nickname(fd, name));
    }
  return (0);
}

int		change_nickname(const int fd, t_list *user,
				const char *new_name)
{
  char		buffer[4096];

  if (((t_udata *)(user->struc))->name != NULL)
    free(((t_udata *)(user->struc))->name);
  if ((((t_udata *)(user->struc))->name = strdup(new_name)) == NULL)
    return (puterr_int(ERR_STRDUP, -1));
  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, RPL_NICKOK, new_name) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  return (answer_client(fd, buffer, -2));
}

int		nick(const int fd, char *command,
		     UNUSED t_list **channel, t_list **users)
{
  t_list	*user;
  t_list	*tmp;
  int		ret_value;

  if (command == NULL)
    return (not_enough_params(fd, *users, "NICK"));
  if ((user = get_user(*users, fd)) == NULL)
    return (puterr_int(ERR_UNKNOWNUSER, -1));
  if ((ret_value = check_new_name(fd, command)) != 0)
    return (ret_value);
  tmp = *users;
  while (tmp != NULL)
    {
      if (!strcasecmp(((t_udata *)(tmp->struc))->name, command))
	return (already_in_use(fd, command));
      tmp = tmp->next;
    }
  return (change_nickname(fd, user, command));
}
