/*
** management.c for management in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 18:44:58 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 19:28:49 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serv.h"
#include "errors.h"
#include "replies.h"

int		change_current_channel(const int fd,
				       t_list **users, char *newChannel)
{
  t_list	*tmp;

  tmp = *users;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd == fd)
	{
	  if (tmp->struc && ((t_udata *)(tmp->struc))->current_channel != NULL)
	    free(((t_udata *)(tmp->struc))->current_channel);
	  if (newChannel != NULL)
	    {
	      if ((((t_udata *)(tmp->struc))->current_channel
		   = strdup(newChannel)) == NULL)
		return (puterr_int(ERR_STRDUP, -1));
	      return (0);
	    }
	  ((t_udata *)(tmp->struc))->current_channel = NULL;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		take_first_arg(const int fd, char **arg,
			       t_list *users, char *command)
{
  char		buffer[4096];

  if ((*arg = strtok(*arg, " ")) == NULL)
    {
      if (memset(buffer, 0, 4096) == NULL)
	return (puterr_int(ERR_MEMSET, -1));
      if (snprintf(buffer, 4096, ERR_NEEDMOREPARAMS,
		   get_user_name(users, fd), command) == -1)
	return (puterr_int(ERR_SNPRINTF, -1));
      if (*arg == NULL)
	return (answer_client(fd, buffer, -2));
    }
  return (0);
}

int		take_two_args(char **args, char *cmd)
{
  int		i;

  i = 0;
  while (i < 2)
    {
      if ((args[i] = strtok(i == 0 ? cmd : NULL, i == 0 ? " " : "")) == NULL)
	return (-1);
      ++i;
    }
  args[i] = NULL;
  if (i != 2)
    return (-1);
  return (0);
}

t_list		*add_new_user(t_socket *serv, t_list *users)
{
  t_udata	*data;

  if ((data = malloc(sizeof(t_udata))) == NULL)
    return (puterr(ERR_MALLOC, NULL));
  if ((data->fd = serv->accept(serv, NULL)) == -1 ||
      !create_buffer(&data->buffs))
    return (NULL);
  data->name = "Anonymous";
  if ((data->name = strdup("Anonymous")) == NULL)
    return (puterr(ERR_STRDUP, NULL));
  data->current_channel = NULL;
  if (users == NULL)
    users = create_list(data, NULL);
  else if ((users)->push_back(users, data) == NULL)
    return (puterr(ERR_PUSHBACKUSER, NULL));
  if (users == NULL)
    return (puterr(ERR_LISTNULL, NULL));
  return (users);
}
