/*
** channels.c for channels in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 16:40:24 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 18:44:43 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serv.h"

t_channel		*createNewChannel(const char *name)
{
  t_channel		*newChannel;

  if (name == NULL)
    {
      fprintf(stderr, "Error: name of a channel cannot be NULL\n");
      return (NULL);
    }
  if ((newChannel = malloc(sizeof(t_channel))) == NULL)
    {
      fprintf(stderr, "Error: malloc failed.\n");
      return (NULL);
    }
  newChannel->users = NULL;
  newChannel->name = name;
  newChannel->next = NULL;
  return (newChannel);
}

int			addChannel(t_channel *template, t_channel *toAdd)
{
  t_channel		*tmp;

  if (!toAdd)
    {
      fprintf(stderr, "Error: cannot add a channel to the server.\n");
      return (-1);
    }
  tmp = template;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = toAdd;
  return (0);
}

void			freeChannel(t_channel *template, const char *name)
{
  t_channel		*tmp;
  t_channel		*save;

  tmp = template;
  while (tmp->next != NULL)
    {
      if (!strcmp(tmp->next->name, name))
	{
	  save = tmp->next;
	  tmp->next = tmp->next->next;
	  free(save);
	  return ;
	}
      tmp = tmp->next;
    }
}

void			freeChannels(t_channel *template)
{
  t_channel		*tmp;
  t_channel		*save;

  tmp = template;
  while (tmp != NULL)
    {
      save = tmp;
      tmp = tmp->next;
      free(save);
    }
}
