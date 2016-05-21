/*
** manage_fd.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Sat May 21 22:16:57 2016 guillaume wilmot
** Last update Sat May 21 22:33:50 2016 guillaume wilmot
*/

#include <stdio.h>
#include <stdlib.h>
#include "serv.h"

int			check_and_read(fd_set *readf, t_list **users)
{
  t_list		*tmp;
  t_udata		*struc;
  int			ret;

  tmp = *users;
  while (tmp)
    {
      struc = tmp->struc;
      struc->buffs.cmds ? free_content(struc->buffs.cmds) : 0;
      struc->buffs.cmds ? struc->buffs.cmds->destroy(struc->buffs.cmds) : 0;
      struc->buffs.cmds = NULL;
      if (FD_ISSET(struc->fd, readf))
        {
          if ((ret = get_cmd_buff(struc->fd, &struc->buffs) == -1))
            return (-1);
          else if (ret == -2)
            puts("handle overflow");
        }
      tmp = tmp->next;
    }
  return (0);
}

int			check_and_write(fd_set *writef, t_list **users)
{
  t_list		*tmp;
  t_udata		*struc;
  int			ret;

  tmp = *users;
  while (tmp)
    {
      struc = tmp->struc;
      if (FD_ISSET(struc->fd, writef))
        {
          if ((ret = get_cmd_buff(struc->fd, &struc->buffs) == -1))
            return (-1);
          else if (ret == -2)
            puts("handle overflow");
        }
      tmp = tmp->next;
    }
  return (0);
}

int			set_select_fd(t_socket *socket, t_list *users,
                                      fd_set *readf, fd_set *writef)
{
  t_list		*tmp;
  int			higher_fd;
  int			fd;

  tmp = users;
  higher_fd = socket->fd > 0 ? socket->fd : 0;
  if (socket && socket->fd != -1)
    {
      FD_SET(socket->fd, readf);
      FD_SET(socket->fd, writef);
    }
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd != -1)
        {
          fd = ((t_udata *)(tmp->struc))->fd;
	  higher_fd = fd > higher_fd ? fd : higher_fd;
          FD_SET(fd, readf);
	  FD_SET(fd, writef);
        }
      tmp = tmp->next;
    }
  return (higher_fd);
}
