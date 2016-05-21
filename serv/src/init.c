/*
** init.c for init in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 14:50:18 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 22:32:34 2016 Nyrandone Noboud-Inpeng
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
  code[5] = "NAMES";
  code[6] = "MSG";
  code[7] = "SENDFILE";
  code[8] = "ACCEPTFILE";
  code[9] = "QUIT";
  code[10] = NULL;
}

void		init_ptrfunc(int (**func)(const int, char *,
					  t_list **, t_list **))
{
  func[0] = &nick;
  func[1] = &list;
  func[2] = &join;
  func[3] = &part;
  func[4] = &users;
  func[5] = &names;
  func[6] = &msg;
  func[7] = &send_file;
  func[8] = &accept_file;
  func[9] = &quit;
  func[10] = NULL;
}
