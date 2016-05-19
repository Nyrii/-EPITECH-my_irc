/*
** management.c for management in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 18:44:58 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:11:07 2016 Nyrandone Noboud-Inpeng
*/

#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"
#include "errors.h"

t_list		*addNewUser(t_socket *serv, t_list *users)
{
  t_udata	*data;

  if ((data = malloc(sizeof(t_udata))) == NULL)
    return (puterr(ERR_MALLOC, NULL));
  if ((data->fd = serv->accept(serv, NULL)) == -1)
    return (NULL);
  data->name = "Anonymous";
  data->current_channel = NULL;
  if (users == NULL)
    users = create_list(data, NULL);
  else if ((users)->push_back(users, data) == -1)
    return (puterr("Error: push back of users failed.\n", NULL));
  if (users == NULL)
    return (puterr("Error: list of users NULL.\n", NULL));
  return (users);
}
