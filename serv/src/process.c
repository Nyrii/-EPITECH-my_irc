/*
** process.c for process in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 02:24:12 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 03:02:34 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serv.h"
#include "socket.h"
#include "errors.h"

static void		init_code(char **code)
{
  code[0] = "NICK";
  code[1] = "LIST";
  code[2] = "JOIN";
  code[3] = "PART";
  code[4] = "USERS";
  code[5] = "MSG";
  code[6] = "SENDFILE";
  code[7] = "ACCEPTFILE";
  code[8] = NULL;
}

static void		init_ptrfunc(int (**func)(int, char *,
					  t_list **, t_list *))
{
  func[0] = &nick;
  func[1] = &list;
  func[2] = &join;
  func[3] = &part;
  func[4] = &users;
  func[5] = &msg;
  func[6] = &send_file;
  func[7] = &accept_file;
  func[8] = NULL;
}

int			process(t_processdata *pdata, t_socket *socket,
				t_list **channels, t_list *users)
{
  char			*code[9];
  int			(*func[9])(int, char *, t_list **, t_list *);
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
	  if ((func[i](pdata->fd, strtok(pdata->command, "\r\n"),
		       channels, users)) == -1)
	    return (socket->fd != -1 ? close_socket(socket) : -1);
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
	{}
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
	  /**/
	  t_list	*tmp = users;

	  while (tmp != NULL)
	    {
	      printf("tmp->fd = %d\n", ((t_udata *)(tmp->struc))->fd);
	      tmp = tmp->next;
	    }
	  /**/
	}
      if (checkAndProcess(&readf, socket, &channels, users) == -1)
	return (closeAndFree(socket, users, channels, -1));
      saveChannels(channels);
    }
}
