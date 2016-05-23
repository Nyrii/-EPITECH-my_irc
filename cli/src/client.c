/*
** client.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 17:38:27 2016 guillaume wilmot
** Last update Tue May 24 01:50:31 2016 guillaume wilmot
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "errors.h"
#include "socket.h"
#include "circular_buffer.h"

void			set_fds(fd_set *writef, fd_set *readf,
				int fd, t_buffs *buffs)
{
  if (writef)
    FD_ZERO(writef);
  if (readf)
    FD_ZERO(readf);
  if (fd != -1)
    {
      if (buffs->out.start != buffs->out.end)
	writef ? FD_SET(fd, writef) : 0;
      readf ? FD_SET(fd, readf) : 0;
    }
  readf ? FD_SET(0, readf) : 0;
}

char			*read_all(int fd, fd_set *readf, t_buffs *buffs)
{
  t_list                *tmp_cmd;
  int			ret;

  buffs->cmds ? free_content(buffs->cmds) : 0;
  buffs->cmds ? buffs->cmds->destroy(buffs->cmds) : 0;
  buffs->cmds = NULL;
  if (FD_ISSET(fd, readf))
    {
      if ((ret = get_cmd_buff(fd, buffs)) == -1)
	return (NULL);
      else if (ret == -3)
	return (NULL);
      else if (ret == -2)
	puterr("Reply too long\n", 0);
    }
  tmp_cmd = buffs->cmds;
  while (tmp_cmd)
    {
      fprintf(stderr, "%s\n", (char *)tmp_cmd->struc);
      tmp_cmd = tmp_cmd->next;
    }
  if (FD_ISSET(0, readf))
    return (get_next_line(0));
  return ("");
}

int			write_all(fd_set *writef, t_buffs *buffs, int fd)
{
  char			*buff;
  int                   ret;

  if (FD_ISSET(fd, writef))
    if ((buff = get_buff_content(&buffs->out)))
      {
	if ((ret = write(fd, buff, strlen(buff)) == -1))
	  return (puterr_int(ERR_ANSWER, -1));
	free(buff);
      }
  return (0);
}

int			wait_for_input(t_socket *socket)
{
  t_buffs		buffs;
  fd_set		fs[2];
  char			*cmd;
  struct timeval	tv;

  if (!create_buffer(&buffs))
    return (-1);
  while (1)
    {
      tv.tv_sec = 1;
      tv.tv_usec = 0;
      set_fds(&fs[1], &fs[0], socket->fd, &buffs);
      if (select(socket->fd != -1 ? socket->fd + 1 : 1,
		 &fs[0], &fs[1], NULL, &tv) == -1)
	return (puterr_int(ERR_SELECT, -1));
      if (!(cmd = read_all(socket->fd, &fs[0], &buffs)) ||
	  write_all(&fs[1], &buffs, socket->fd) == -1 ||
	  (cmd && strcmp(cmd, "") && parse_cmd(cmd, socket, &buffs) == -1))
	return (-1);
    }
}
