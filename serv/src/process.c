/*
** process.c for process in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 02:24:12 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 19:24:09 2016 Nyrandone Noboud-Inpeng
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

int			process(t_processdata *pdata,
				t_list **channels, t_list *users)
{
  char			*code[9];
  int			(*func[9])(const int, char *,
				   t_list **, t_list *);
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

int			checkAndProcess(fd_set *readf, t_socket *socket,
					t_list **channels, t_list *users)
{
  t_list		*tmp;
  t_processdata		pdata;

  (void)channels;
  (void)socket;
  (void)pdata;
  tmp = users;
  while (tmp != NULL)
    {
      if (FD_ISSET(((t_udata *)(tmp->struc))->fd, readf))
	{
	  pdata.command = get_cmd_buff(((t_udata *)(tmp->struc))->fd,
				       &((t_udata *)(tmp->struc))->buff);
	  replaceEndOfString(&pdata.command);
	  pdata.fd = ((t_udata *)(tmp->struc))->fd;
	  process(&pdata, channels, users);
	}
      tmp = tmp->next;
    }
  return (0);
}

int			core(t_socket *socket, t_list *channels, t_list *users)
{
  fd_set		readf;
  struct timeval	tv;

  while (1)
    {
      tv.tv_sec = 5;
      tv.tv_usec = 0;
      FD_ZERO(&readf);
      setSelectFd(socket, users, &readf);
      if (select(getHigherFd(socket, users) + 1,
		 &readf, NULL, NULL, &tv) == -1)
	return (puterr_int("Error: select failed.\n", -1));
      if (FD_ISSET(socket->fd, &readf))
	{
	  if ((users = addNewUser(socket, users)) == NULL)
	    return (closeAndFree(socket, users, channels, -1));
	  saveUsers(users);
	}
      if (checkAndProcess(&readf, socket, &channels, users) == -1)
	return (closeAndFree(socket, users, channels, -1));
      saveChannels(channels);
    }
}
