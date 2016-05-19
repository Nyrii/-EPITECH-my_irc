/*
** send_message.c for send_message in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Thu May 19 18:40:35 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 18:58:01 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <stdio.h>
#include "serv.h"

int		joinSucceed(const int fd, t_list *current_channel)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, ERR_NEEDMOREPARAMS,
	       getUserName(users, fd), "JOIN") == -1)
    return (puterr_int("Error: snprintf failed.\n", -1));
  return (0);
}
