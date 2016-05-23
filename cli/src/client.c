/*
** client.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 17:38:27 2016 guillaume wilmot
** Last update Mon May 23 14:39:08 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "errors.h"
#include "socket.h"
#include "circular_buffer.h"

void			set_fds(fd_set *writef, fd_set *readf)
{
  writef ? FD_ZERO(&writef) : 0;
  readf ? FD_ZERO(&readf);
  if (socket->fd != -1)
    {
      writef ? FD_SET(socket->fd, writef) : 0;
      readf ? FD_SET(socket->fd, readf) : 0;
    }
  readf ? FD_SET(0, readf) : 0;
}

int			check_and_read(t_socket *socket, char **code,
				       int (**func)(char *, t_socket *),
				       fd_set *fs[2])
{

}

int			wait_for_input(t_socket *socket, char **code,
			       int (**func)(char *, t_socket *))
{
  t_buffs		buffs;
  fd_set		fs[2];
  char			*cmd;
  struct timeval	tv;

  tv.tv_sec = 5;
  tv.tv_usec = 0;
  while (1)
    {
      set_fds(&writef[0], &readf[0]);
      if (select(socket->fd != -1 ? socket->fd + 1 : 1,
		 &readf, &writef, NULL, &tv) == -1)
	return (puterr_int("Error: select failed.\n", -1));
      check_and_read(socket, code, fund, &fs);
      if (FD_ISSET(0, &std) && !(cmd = get_next_line(0)))
	return (-1);
      cmd ? printf("%s\n", cmd) : 0;
      fflush(stdout);
      cmd = NULL;
    }
}
