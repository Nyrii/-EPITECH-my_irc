/*
** server_sockets.c for server_sockets in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 18:02:07 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:15:23 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <unistd.h>
#include "serv.h"
#include "errors.h"

t_socket	*initServerSocket()
{
  t_socket	*socket;
  int		istrue;

  istrue = 1;
  if ((socket = create_socket()) == NULL
      || socket->init(socket, 6667, "TCP", INADDR_ANY) == -1
      || setsockopt(socket->fd, SOL_SOCKET, SO_REUSEADDR, &istrue, sizeof(int)) == -1
      || socket->bind(socket) == -1
      || socket->listen(socket) == -1)
    return (NULL);
  saveSocket(socket);
  return (socket);
}

int		getHigherFd(t_socket *socket, t_list *users)
{
  int		higher_fd;
  t_list	*tmp;

  tmp = users;
  higher_fd = 0;
  if (socket && socket->fd != -1)
    higher_fd = socket->fd;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd > higher_fd)
	higher_fd = ((t_udata *)(tmp->struc))->fd;
      tmp = tmp->next;
    }
  return (higher_fd);
}

int		setSelectFd(t_socket *socket, t_list *users, fd_set *readf)
{
  t_list	*tmp;

  tmp = users;
  if (socket && socket->fd != -1)
    FD_SET(socket->fd, readf);
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd != -1)
	FD_SET(((t_udata *)(tmp->struc))->fd, readf);
      tmp = tmp->next;
    }
  return (0);
}

int		close_all_sockets(t_socket *socket,
				  t_list *users, int ret_value)
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
  return (ret_value);
}
