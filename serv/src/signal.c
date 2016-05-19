/*
** signal.c for signal in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 02:12:34 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:14:06 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "socket.h"

t_socket		*saveSocket(t_socket *server)
{
  static t_socket	*tmp = NULL;

  if (server != NULL)
    tmp = server;
  return (tmp);
}

void			clean_socket()
{
  t_socket		*tmp;

  if ((tmp = saveSocket(NULL)) != NULL)
    {
      if (tmp->fd != -1 && close(tmp->fd) == -1)
	fprintf(stderr, "Error: cannot close the server file descriptor.\n");
    }
  exit(0);
}
