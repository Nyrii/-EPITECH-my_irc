/*
** delete.c for delete in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Fri May 20 13:54:04 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 21:00:33 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "serv.h"

void		deleteUserFromChannels(const int fd, t_list **channel)
{
  int		index;
  t_list	*tmp_users;
  t_list	*tmp_channel;
  int		i;

  i = 0;
  tmp_channel = *channel;
  while (tmp_channel != NULL)
    {
      tmp_users = ((t_cdata *)(tmp_channel->struc))->users;
      if ((index = getIndexUserFromChannel(*channel, fd)) != -1)
	tmp_users = tmp_users->delete_nth(tmp_users, index);
      if (tmp_users == NULL)
	{
	  free(((t_cdata *)((*channel)->struc))->name);
	  free((*channel)->struc);
	  *channel = (*channel)->delete_nth(*channel, i);
          tmp_channel = *channel ? tmp_channel : NULL;
	}
      ++i;
      if (tmp_channel)
	tmp_channel = tmp_channel->next;
    }
}

void		deleteUserFromUsersList(const int fd, t_list **users)
{
  int		i;
  t_list	*tmp;

  if ((tmp = getUser(*users, fd)) == NULL)
    return ;
  if ((i = getIndexUserFromUsersList(*users, fd)) == -1)
    return ;
  free(((t_udata *)(tmp->struc))->name);
  free(((t_udata *)(tmp->struc))->current_channel);
  free(tmp->struc);
  tmp->struc = NULL;
  *users = (*users)->delete_nth(*users, i);
}
