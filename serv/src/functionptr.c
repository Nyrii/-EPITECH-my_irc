/*
** functionptr.c for functionptr in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 16:26:39 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 20:09:30 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
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
					  t_list *, t_list *))
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
				t_list *channels, t_list *users)
{
  char			*code[9];
  int			(*func[9])(int, char *, t_list *, t_list *);
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
  (void)channels;
  (void)users;
  return (0);
}
