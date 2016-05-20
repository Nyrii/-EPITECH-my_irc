/*
** free.c for free in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Fri May 20 13:35:19 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 20:59:25 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <unistd.h>
#include "errors.h"
#include "serv.h"

void		freeChannelsStructures(t_list *channels)
{
  t_list	*tmp;
  t_list	*tmp_cdata;

  tmp = channels;
  while (tmp != NULL)
    {
      tmp_cdata = ((t_cdata *)(tmp->struc))->users;
      tmp_cdata->destroy(tmp_cdata);
      if (tmp->struc != NULL)
	{
	  free(((t_cdata *)(tmp->struc))->name);
	  free(tmp->struc);
	  tmp->struc = NULL;
	}
      tmp = tmp->next;
    }
}

int		closeAndFree(t_socket *socket, t_list *users,
			     t_list *channels, int ret_value)
{
  t_list	*tmp;
  t_list	*tmp_free;

  tmp = users;
  if (socket && socket->fd != -1)
    {
      if (socket->close(socket) == -1)
	return (-1);
    }
  while (tmp != NULL)
    {
      if (((t_udata *)(tmp->struc))->fd != -1)
	{
	  if (close(((t_udata *)(tmp->struc))->fd) == -1)
	    return (puterr_int(ERR_CLOSE, -1));
	}
      tmp_free = tmp;
      tmp = tmp->next;
      free(((t_udata *)(tmp_free->struc))->name);
      free(((t_udata *)(tmp_free->struc))->current_channel);
      free(tmp_free->struc);
      tmp_free->struc = NULL;
    }
  channels ? freeChannelsStructures(channels) : 0;
  users ? users->destroy(users) : 0;
  channels ? channels->destroy(channels) : 0;
  return (socket ? free(socket) : 0, ret_value);
}
