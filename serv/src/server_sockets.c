/*
** server_sockets.c for server_sockets in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 18:02:07 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 23:03:09 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "serv.h"
#include "errors.h"

int		answerClient(int fd, const char *answer, int ret_value)
{
  if (write(fd, answer, strlen(answer)) == -1)
    return (puterr_int("Error: could not write to client(s).\n", -1));
  return (ret_value);
}

t_socket	*initServerSocket(const int port)
{
  t_socket	*socket;
  int		istrue;

  istrue = 1;
  if ((socket = create_socket()) == NULL
      || socket->init(socket, port, "TCP", INADDR_ANY) == -1
      || setsockopt(socket->fd, SOL_SOCKET, SO_REUSEADDR,
		    &istrue, sizeof(int)) == -1
      || socket->bind(socket) == -1
      || socket->listen(socket) == -1)
    return (NULL);
  saveSocket(socket);
  return (socket);
}

int		closeAndFree(t_socket *socket, t_list *users,
			     t_list *channels, int ret_value)
{
  t_list	*tmp;

  tmp = users;
  if (socket && socket->fd != -1)
    {
      if (socket->close(socket) == -1)
	return (-1);
    }
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd != -1)
	{
	  if (close(((t_udata *)(tmp->struc))->fd) == -1)
	    return (puterr_int(ERR_CLOSE, -1));
	}
      tmp = tmp->next;
    }
  users ? users->destroy(users) : 0;
  channels ? channels->destroy(channels) : 0;
  socket ? free(socket) : 0;
  return (ret_value);
}
