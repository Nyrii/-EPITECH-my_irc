/*
** server_sockets.c for server_sockets in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 18:02:07 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 21:56:54 2016 Nyrandone Noboud-Inpeng
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
  saveSocket(socket, 1);
  return (socket);
}
