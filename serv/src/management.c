/*
** management.c for management in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 18:44:58 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 19:19:51 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include "circular_buffer.h"
#include "serv.h"
#include "errors.h"

t_list		*getUser(t_list *users, const int fd)
{
  t_list	*tmp;

  tmp = users;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

char		*getUserName(t_list *users, const int fd)
{
  t_list	*tmp;

  tmp = users;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd == fd)
	return (((t_udata *)(tmp->struc))->name);
      tmp = tmp->next;
    }
  return (NULL);
}

t_list		*addNewUser(t_socket *serv, t_list *users)
{
  t_udata	*data;

  if ((data = malloc(sizeof(t_udata))) == NULL)
    return (puterr(ERR_MALLOC, NULL));
  if ((data->fd = serv->accept(serv, NULL)) == -1)
    return (NULL);
  if (memset(&(data->buff), 0, sizeof(t_buff)) == NULL)
    return (puterr(ERR_MEMSET, NULL));
  data->name = "Anonymous";
  data->current_channel = NULL;
  if (users == NULL)
    users = create_list(data, NULL);
  else if ((users)->push_back(users, data) == NULL)
    return (puterr("Error: push back of users failed.\n", NULL));
  if (users == NULL)
    return (puterr("Error: list of users NULL.\n", NULL));
  return (users);
}
