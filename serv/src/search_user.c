/*
** search_user.c for searchuser in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 21:30:01 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 02:22:26 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "serv.h"

int		get_index_user_from_users_list(t_list *users, const int fd)
{
  t_list	*tmp;
  int		i;

  i = 0;
  if (users == NULL)
    return (-1);
  tmp = users;
  while (tmp != NULL)
    {
      if (tmp->struc && ((t_udata *)(tmp->struc))->fd == fd)
	return (i);
      ++i;
      tmp = tmp->next;
    }
  return (-1);
}

int		get_index_user_from_channel(t_list *channels, const int fd)
{
  t_list	*tmp;
  int		i;

  i = 0;
  if (channels == NULL)
    return (-1);
  tmp = ((t_cdata *)(channels->struc))->users;
  while (tmp != NULL)
    {
      if (tmp->struc && ((t_udata *)(tmp->struc))->fd == fd)
	return (i);
      ++i;
      tmp = tmp->next;
    }
  return (-1);
}

t_list		*get_user(t_list *users, const int fd)
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

char		*get_user_name(t_list *users, const int fd)
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
