/*
** main.c for main.c in /Users/noboud_n/Documents/Share/PSU_2015_myirc/client/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:36:21 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 23 23:03:07 2016 guillaume wilmot
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "errors.h"
#include "client.h"
#include "socket.h"
#include "list.h"

void		init_code_bis(char **code)
{
  code[0] = NULL;
  code[1] = "NICK";
  code[2] = "LIST";
  code[3] = "JOIN";
  code[4] = "PART";
  code[5] = "USERS";
  code[6] = "PRIVMSG";
  code[7] = NULL;
  code[8] = NULL;
  code[9] = "NAMES";
  code[10] = "QUIT";
  code[11] = NULL;
}

void		init_code(char **code)
{
  code[0] = "/server";
  code[1] = "/nick";
  code[2] = "/list";
  code[3] = "/join";
  code[4] = "/part";
  code[5] = "/users";
  code[6] = "/msg";
  code[7] = "/send_file";
  code[8] = "/accept_file";
  code[9] = "/names";
  code[10] = "/quit";
  code[11] = NULL;
}

void		init_ptrfunc(int (**func)(t_socket *, t_buffs *, char *))
{
  func[0] = &server;
  func[1] = &nick;
  func[2] = &nick;
  func[3] = &nick;
  func[4] = &nick;
  func[5] = &nick;
  func[6] = &nick;
  func[7] = &send_file;
  func[8] = &accept_file;
  func[9] = &nick;
  func[10] = &quit;
  func[11] = NULL;
}

int		main()
{
  t_socket	*socket;

  if ((socket = create_socket()) == NULL)
    return (-1);
  return (wait_for_input(socket));
}
