/*
** process.c for process in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 02:24:12 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 15:58:15 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serv.h"
#include "socket.h"
#include "errors.h"

static void		replaceEndOfString(char **string)
{
  int			i;

  if (!(*string))
    return ;
  i = strlen(*string);
  if (i > 1 && (*string)[i - 1] == '\n' && (*string)[i - 2] == '\r')
    (*string)[i - 2] = '\0';
  return ;
}

static int		process(t_processdata *pdata,
				t_list **channels, t_list **users)
{
  char			*code[10];
  int			(*func[10])(const int, char *,
				   t_list **, t_list **);
  int			i;
  char			*function_to_call;

  i = -1;
  init_code(code);
  init_ptrfunc(func);
  if ((function_to_call = strtok(pdata->command, " ")) == NULL)
    return (puterr_int(ERR_SYNTAX, -2));
  while (code[++i] != NULL)
    {
      if (!strcmp(code[i], function_to_call))
	{
	  if ((func[i](pdata->fd, strtok(NULL, ""),
		       channels, users)) == -1)
	    return (-1);
	}
    }
  return (0);
}

static int		checkAndProcess(fd_set *readf, t_list **channels,
					t_list **users)
{
  t_list		*tmp;
  t_processdata		pdata;
  int			fd;

  tmp = *users;
  while (tmp != NULL)
    {
      pdata.command = NULL;
      pdata.fd = -1;
      fd = ((t_udata *)(tmp->struc))->fd;
      if (FD_ISSET(fd, readf))
	{
	  FD_CLR(fd, readf);
	  pdata.command = get_cmd_buff(fd, &((t_udata *)(tmp->struc))->buff);
	  replaceEndOfString(&pdata.command);
	  pdata.fd = fd;
	  if (pdata.command != NULL)
	    {
	      if (process(&pdata, channels, users) == -1)
		return (-1);
	      saveUsers(*users, 1);
	      saveChannels(*channels, 1);
	      tmp = *users ? tmp : NULL;
	    }
	}
      if (tmp)
	tmp = tmp->next;
    }
  return (0);
}

static int		setSelectFd(t_socket *socket, t_list *users,
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
      higher_fd = setSelectFd(socket, users, &readf);
      if (select(higher_fd + 1, &readf, NULL, NULL, &tv) == -1)
	return (puterr_int(ERR_SELECT, -1));
      if (FD_ISSET(socket->fd, &readf))
	{
	  if ((users = addNewUser(socket, users)) == NULL)
	    return (closeAndFree(socket, users, channels, -1));
	  saveUsers(users, 1);
	}
      if (checkAndProcess(&readf, &channels, &users) == -1)
	return (closeAndFree(socket, users, channels, -1));
    }
}
