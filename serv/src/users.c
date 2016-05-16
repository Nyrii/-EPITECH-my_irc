/*
** users.c for users in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 19:13:22 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 20:15:51 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "serv.h"

int			createNewUser(t_users *user)
{
  // Connect to socket (class ?)

  user->fd = -1;
  user->name = "Anonymous";
  user->next = NULL;
  user->channelname = NULL;
  return (0);
}

int			addUserAtEnd(t_users *users, t_users *toAdd)
{
  t_users		*tmp;

  tmp = users;
  toAdd->fd = -1;
  toAdd->name = "Anonymous";
  toAdd->next = NULL;
  toAdd->channelname = NULL;
  while (tmp->next != NULL)
    tmp = tmp->next;
  users->next = toAdd;
  return (0);
}

int			addUser(t_users *users)
{
  t_users		*newUser;

  if (users == NULL)
    {
      if ((users = malloc(sizeof(t_users))) == NULL)
	{
	  fprintf(stderr, "Error: malloc failed.\n");
	  return (-1);
	}
      return (createNewUser(users));
    }
  else if ((newUser = malloc(sizeof(t_users))) == NULL)
    {
      fprintf(stderr, "Error: malloc failed.\n");
      return (-1);
    }
  return (addUserAtEnd(users, newUser));
}

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

void			freeUsers(t_users *template)
{
  t_users		*tmp;
  t_users		*save;

  tmp = template;
  while (tmp != NULL)
    {
      save = tmp;
      tmp = tmp->next;
      free(save);
    }
}
