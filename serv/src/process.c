/*
** process.c for process in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 02:24:12 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 18:51:16 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serv.h"
#include "socket.h"
#include "errors.h"

static int		process(t_processdata *pdata,
				t_list **channels, t_list **users)
{
  char			*code[11];
  int			(*func[11])(const int, char *,
				   t_list **, t_list **);
  int			i;
  char			*function_to_call;

  i = -1;
  init_code(code);
  init_ptrfunc(func);
  if ((function_to_call = strtok(pdata->command, " ")) == NULL)
    return (puterr_int(ERR_SYNTAX, -2));
  while (code[++i] != NULL)
    if (!strcmp(code[i], function_to_call))
      {
	if (func[i](pdata->fd, strtok(NULL, ""), channels, users) == -1)
	  return (-1);
	save_users(*users, 1);
	save_channels(*channels, 1);
	return (0);
      }
  return (puterr_int(ERR_SYNTAX, 0));
}

static int		process_all(t_list **channels, t_list **users)
{
  t_list		*tmp;
  t_list		*tmp_cmd;
  t_list		*next;
  t_list		*next_cmd;
  t_processdata		pdata;

  tmp = *users;
  while (tmp)
    {
      tmp_cmd = ((t_udata *)(tmp->struc))->buffs.cmds;
      next = tmp->next;
      while (tmp_cmd)
	{
	  pdata.fd = ((t_udata *)(tmp->struc))->fd;
	  pdata.command = tmp_cmd->struc;
	  next_cmd = tmp_cmd->next;
	  if (process(&pdata, channels, users) == -1)
	    return (-1);
	  tmp_cmd = *users ? next_cmd : NULL;
	}
      tmp = *users ? next : NULL;
    }
  return (0);
}

static int		check_and_read(fd_set *readf, t_list **users)
{
  t_list		*tmp;
  int			ret;

  tmp = *users;
  while (tmp)
    {
      if (FD_ISSET(((t_udata *)(tmp->struc))->fd, readf))
	{
	  if ((ret = get_cmd_buff(((t_udata *)(tmp->struc))->fd,
				  &((t_udata *)(tmp->struc))->buffs) == -1))
	    return (-1);
	  else if (ret == -2)
	    puts("handle overflow");
	  else if (ret == -3)
	    return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}

static int		set_select_fd(t_socket *socket, t_list *users,
				      fd_set *readf)
{
  t_list		*tmp;
  int			higher_fd;
  int			fd;

  tmp = users;
  higher_fd = 0;
  if (socket->fd > higher_fd)
    higher_fd = socket->fd;
  if (socket && socket->fd != -1)
    FD_SET(socket->fd, readf);
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd != -1)
	{
	  fd = ((t_udata *)(tmp->struc))->fd;
	  if (fd > higher_fd)
	    higher_fd = fd;
	  FD_SET(fd, readf);
	}
      tmp = tmp->next;
    }
  return (higher_fd);
}

int			core(t_socket *socket, t_list *channels, t_list *users)
{
  fd_set		readf;
  struct timeval	tv;
  int			higher_fd;

  while (1)
    {
      tv.tv_sec = 5;
      tv.tv_usec = 0;
      FD_ZERO(&readf);
      higher_fd = set_select_fd(socket, users, &readf);
      if (select(higher_fd + 1, &readf, NULL, NULL, &tv) == -1)
	return (puterr_int(ERR_SELECT, -1));
      if (FD_ISSET(socket->fd, &readf))
	{
	  if ((users = add_new_user(socket, users)) == NULL)
	    return (close_and_free(socket, users, channels, -1));
	  save_users(users, 1);
	}
      if (check_and_read(&readf, &users) == -1)
	return (close_and_free(socket, users, channels, -1));
      if (process_all(&channels, &users) == -1)
	return (-1);
    }
}
