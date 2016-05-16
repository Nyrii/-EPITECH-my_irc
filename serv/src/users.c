/*
** users.c for users in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 19:13:22 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 19:30:45 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <stdlib.h>
#include "serv.h"

void			removeUser(t_users *user, const char *username)
{
  t_users		*tmp;
  t_users		*save;

  tmp = user;
  while (tmp->next != NULL)
    {
      if (!strcmp(tmp->next->name, username))
	{
	  save = tmp->next;
	  tmp->next = tmp->next->next;
	  free(save);
	  return ;
	}
      tmp = tmp->next;
    }
}
