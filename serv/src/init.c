/*
** init.c for init in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 14:50:18 2016 Nyrandone Noboud-Inpeng
** Last update Sun May 22 17:32:37 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "serv.h"

void		init_code(char **code)
{
  code[0] = "NICK";
  code[1] = "USER";
  code[2] = "LIST";
  code[3] = "JOIN";
  code[4] = "PART";
  code[5] = "USERS";
  code[6] = "NAMES";
  code[7] = "MSG";
  code[8] = "SENDFILE";
  code[9] = "ACCEPTFILE";
  code[10] = "QUIT";
  code[11] = NULL;
}

void		init_ptrfunc(int (**func)(const int, char *,
					  t_list **, t_list **))
{
  func[0] = &nick;
  func[1] = &user;
  func[2] = &list;
  func[3] = &join;
  func[4] = &part;
  func[5] = &users;
  func[6] = &names;
  func[7] = &msg;
  func[8] = &send_file;
  func[9] = &accept_file;
  func[10] = &quit;
  func[11] = NULL;
}
