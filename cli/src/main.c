/*
** main.c for main.c in /Users/noboud_n/Documents/Share/PSU_2015_myirc/client/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:36:21 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 23:58:52 2016 Nyrandone Noboud-Inpeng
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "socket.h"

static void		init_code(char **code)
{
  code[0] = "/server";
  code[1] = "/nick";
  code[2] = "/list";
  code[3] = "/join";
  code[4] = "/part";
  code[5] = "/users";
  code[6] = "/msg";
  code[7] = "/sendfile";
  code[8] = "/accept_file";
  code[9] = NULL;
}

static void		init_ptrfunc(int (**func)(char *, t_socket *))
{
  func[0] = &server;
  func[1] = &nick;
  func[2] = &list;
  func[3] = &join;
  func[4] = &part;
  func[5] = &users;
  func[6] = &msg;
  func[7] = &sendfile;
  func[8] = &acceptfile;
  func[9] = NULL;
}

int		main()
{
  char		*code[10];
  int		(*func[10])(char *, t_socket *);
  char		*buffer;
  char		*command;
  t_socket	*socket;
  int		i;

  init_code(code);
  init_ptrfunc(func);
  socket = NULL;
  i = 0;
  while ((buffer = get_next_line(0)))
    {
      i = 0;
      command = strtok(buffer, " ");
      while (code[i] != NULL)
	{
	  if (!strcmp(code[i], command))
	    {
	      if (func[i](strtok(NULL, ""), socket) == -1)
		return (-1);
	    }
	}
      buffer ? free(buffer) : 0;
    }
  return (0);
}
