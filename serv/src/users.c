/*
** users.c for users in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 19:13:22 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 02:23:06 2016 Nyrandone Noboud-Inpeng
*/

#include "serv.h"

int		users(const int fd, char *command,
		      t_list **channel, t_list **users)
{
  (void)fd;
  (void)command;
  (void)channel;
  (void)users;
  return (0);
}

void		set_user(t_udata *user, int fd,
			char *name, char *current_channel)
{
  user->fd = fd;
  user->name = name;
  user->current_channel = current_channel;
}
