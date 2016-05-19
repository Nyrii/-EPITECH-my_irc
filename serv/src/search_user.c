/*
** search_user.c for searchuser in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 21:30:01 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 21:30:36 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "serv.h"

t_list		*getUser(t_list *users, const int fd)
{
  t_list	*tmp;

  tmp = users;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

char		*getUserName(t_list *users, const int fd)
{
  t_list	*tmp;

  tmp = users;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd == fd)
	return (((t_udata *)(tmp->struc))->name);
      tmp = tmp->next;
    }
  return (NULL);
}
