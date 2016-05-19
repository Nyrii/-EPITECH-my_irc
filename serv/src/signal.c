/*
** signal.c for signal in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 02:12:34 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:49:29 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "serv.h"

t_socket		*saveSocket(t_socket *server)
{
  static t_socket	*tmp = NULL;

  if (server != NULL)
    tmp = server;
  return (tmp);
}

t_list			*saveUsers(t_list *users)
{
  static t_list		*tmp = NULL;

  if (users != NULL)
    tmp = users;
  return (tmp);
}

t_list			*saveChannels(t_list *channels)
{
  static t_list		*tmp = NULL;

  if (channels != NULL)
    tmp = channels;
  return (tmp);
}

void			clean_socket()
{
  closeAndFree(saveSocket(NULL), saveUsers(NULL), saveChannels(NULL), 0);
  exit(0);
}
