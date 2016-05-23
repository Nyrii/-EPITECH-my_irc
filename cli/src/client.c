/*
** client.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 17:38:27 2016 guillaume wilmot
** Last update Mon May 23 18:33:21 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "errors.h"
#include "socket.h"
#include "circular_buffer.h"

void			set_fds(fd_set *writef, fd_set *readf, int fd)
{
  if (writef)
    FD_ZERO(writef);
  if (readf)
    FD_ZERO(readf);
  if (fd != -1)
    {
      writef ? FD_SET(fd, writef) : 0;
      readf ? FD_SET(fd, readf) : 0;
    }
  readf ? FD_SET(0, readf) : 0;
}

char			*read_all(int fd, fd_set *fs, t_buffs *buffs)
{
  if (FD_ISSET(fd, fs))
    get_cmd_buff(fd, buffs);
  if (FD_ISSET(0, fs))
    return (get_next_line(0));
  return (NULL);
}

int			write_all()
{
  return (0);
}

int			print_replies(t_buffs *buffs)
{
  (void)buffs;
  return (0);
}

int			wait_for_input(t_socket *socket)
{
  t_buffs		buffs;
  fd_set		fs[2];
  char			*cmd;
  struct timeval	tv;

  tv.tv_sec = 5;
  tv.tv_usec = 0;
  while (1)
    {
      set_fds(&fs[1], &fs[0], socket->fd);
      if (select(socket->fd != -1 ? socket->fd + 1 : 1,
		 &fs[0], &fs[1], NULL, &tv) == -1)
	return (puterr_int(ERR_SELECT, -1));
      cmd = read_all(socket->fd, &fs[0], &buffs);
      if (print_replies(&buffs) == -1 ||
	  (cmd && parse_cmd(cmd, socket, &buffs) == -1))
	return (-1);
    }
}
