/*
** management.c for management in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 18:44:58 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 19:09:58 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"

int			addUserToChannel(t_channel *template, t_users *user)
{
  t_channel		*tmp;

  if (!user)
    {
      fprintf(stderr, "Error: cannot add an user to the channel.\n");
      return (-1);
    }
  if (!template)
    {
      fprintf(stderr, "Error: channel's list is NULL.\n");
      return (-1);
    }
  tmp = template;
  if (tmp->users == NULL)
    tmp->users = user;
  else
    {
      while (tmp->users->next != NULL)
	tmp->users = tmp->users->next;
      tmp->users = user;
    }
  return (0);
}

int			removeUserFromChannel(t_channel *template,
					      const char *username)
{
  t_channel		*tmp;

  if (!username || !template)
    {
      if (!username)
	fprintf(stderr, "Error: cannot remove an user to the channel.\n");
      else
	fprintf(stderr, "Error: channel's list is NULL.\n");
      return (-1);
    }
  tmp = template;
  while (tmp != NULL && !strcmp(tmp->users->name, username))
    tmp = tmp->next;
  if (tmp)
    removeUser(tmp->users, username);
  return (0);
}
