/*
** client.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 17:38:27 2016 guillaume wilmot
** Last update Thu May 19 19:18:26 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "errors.h"
#include "socket.h"
#include "circular_buffer.h"

int		wait_for_input(t_socket *socket, char **code,
			       int (**func)(char *, t_socket *))
{
  t_buff	buff;
  fd_set	std;
  char		*cmd;

  (void)func;
  (void)code;
  while (1)
    {
      FD_ZERO(&std);
      if (socket->fd != -1)
	FD_SET(socket->fd, &std);
      FD_SET(0, &std);
      if (select(socket->fd != -1 ? socket->fd + 1 : 1,
		 &std, NULL, NULL, NULL) == -1)
	return (puterr_int("Error: select failed.\n", -1));
      if (FD_ISSET(socket->fd, &std) && !(cmd = get_cmd_buff(socket->fd, &buff)))
	return (-1);
      cmd ? printf("%s\n", cmd) : 0;
      if (FD_ISSET(0, &std) && !(cmd = get_next_line(0)))
	return (-1);
      cmd ? printf("%s\n", cmd) : 0;
      fflush(stdout);
      cmd = NULL;
    }
}
