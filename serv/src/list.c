/*
** list.c for list in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 17:44:25 2016 Nyrandone Noboud-Inpeng
** Last update Sun May 22 00:17:25 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "serv.h"
#include "replies.h"
#include "errors.h"

int		count_users_in_channel(t_list *channel)
{
  int		i;
  t_list	*users;

  i = 0;
  if ((users = ((t_cdata *)(channel->struc))->users) == NULL)
    return (0);
  while (users != NULL)
    {
      ++i;
      users = users->next;
    }
  return (i);
}

int		list(const int fd, char *command,
		     t_list **channels, t_list **users)
{
  if ((command = strtok(command, " ")) == NULL)
    return (list_all(fd, channels, users));
  return (0);
  // return (find_and_list(fd, channels, users, command));
}
