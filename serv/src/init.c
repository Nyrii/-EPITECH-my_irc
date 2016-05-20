/*
** init.c for init in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 14:50:18 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 17:58:06 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "serv.h"

void		init_code(char **code)
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

void		init_ptrfunc(int (**func)(const int, char *,
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
