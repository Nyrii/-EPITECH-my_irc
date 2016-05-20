/*
** search_channel.c for search_channel in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 21:29:16 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 22:05:18 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include "serv.h"

t_list		*searchChannelByName(t_list *channel, const char *name)
{
  t_list	*tmp;

  tmp = channel;
  while (tmp != NULL)
    {
      if (!strcmp(name, ((t_cdata *)(tmp->struc))->name))
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		searchChannelByUserFd(t_list *channel, const int fd)
{
  t_list	*tmp;

  tmp = ((t_cdata *)(channel->struc))->users;
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd == fd)
	return (0);
      tmp = tmp->next;
    }
  return (-1);
}
