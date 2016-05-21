/*
** delete.c for delete in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Fri May 20 13:54:04 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 18:01:56 2016 guillaume wilmot
*/

#include <stdlib.h>
#include "serv.h"

void		delete_user_from_channels(const int fd, t_list **channel)
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
      if ((index = get_index_user_from_channel(tmp_channel, fd)) != -1)
	{
	  tmp_users = tmp_users->delete_nth(tmp_users, index);
	  ((t_cdata *)(tmp_channel->struc))->users = tmp_users;
	}
      !tmp_users ? free(((t_cdata *)((tmp_channel)->struc))->name) : 0;
      !tmp_users ? free((tmp_channel)->struc) : 0;
      !tmp_users ? ((tmp_channel)->struc = NULL) : 0;
      !tmp_users ? (*channel = (*channel)->delete_nth(*channel, i)) : 0;
      !tmp_users ? (tmp_channel = *channel) : 0;
      i = tmp_users == NULL ? 0 : i + 1;
      tmp_channel = tmp_users == NULL ? tmp_channel : tmp_channel->next;
    }
}

void		delete_user_from_users_list(const int fd, t_list **users)
{
  int		i;
  t_list	*tmp;

  if ((tmp = get_user(*users, fd)) == NULL ||
      (i = get_index_user_from_users_list(*users, fd)) == -1)
    return ;
  free(((t_udata *)(tmp->struc))->name);
  free(((t_udata *)(tmp->struc))->current_channel);
  free_content(((t_udata *)(tmp->struc))->buffs.cmds);
  ((t_udata *)(tmp->struc))->buffs.cmds->destroy
    (((t_udata *)(tmp->struc))->buffs.cmds);
  free(tmp->struc);
  tmp->struc = NULL;
  *users = (*users)->delete_nth(*users, i);
}
