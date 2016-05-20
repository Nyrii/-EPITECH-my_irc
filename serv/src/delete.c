/*
** delete.c for delete in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Fri May 20 13:54:04 2016 Nyrandone Noboud-Inpeng
** Last update Fri May 20 15:46:58 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "serv.h"

#include <stdio.h>
void		deleteUserFromChannels(const int fd, t_list **channel)
{
  int		index;
  t_list	*tmp_users;
  t_list	*tmp_channel;

  tmp_channel = *channel;
  while (tmp_channel != NULL)
    {
      tmp_users = ((t_cdata *)(tmp_channel->struc))->users;
      if ((index = getIndexUserFromChannel(*channel, fd)) != -1)
	*channel = tmp_users->delete_nth(tmp_users, index);
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
  free(tmp->struc);
  tmp->struc = NULL;
  *users = (*users)->delete_nth(*users, i);
}
