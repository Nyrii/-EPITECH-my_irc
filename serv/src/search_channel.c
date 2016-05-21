/*
** search_channel.c for search_channel in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 21:29:16 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 13:43:15 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <string.h>
#include "serv.h"

int		get_index_channel_from_channels_list(t_list *channel,
						     const char *name)
{
  t_list	*tmp;
  int		index;

  index = 0;
  tmp = channel;
  while (tmp != NULL)
    {
      if (!strcmp(name, ((t_cdata *)(tmp->struc))->name))
      	return (index);
      ++index;
      tmp = tmp->next;
    }
  return (-1);
}

t_list		*search_channel_by_name(t_list *channel, const char *name)
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

int		search_channel_by_user_fd(t_list *channel, const int fd)
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
