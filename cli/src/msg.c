/*
** msg.c for msg in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:23:51 2016 Nyrandone Noboud-Inpeng
** Last update Tue May 17 01:10:57 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <unistd.h>
#include "socket.h"
#include "errors.h"

int		msg(char *command, t_socket *socket)
{
  if (socket->fd == -1)
    return (puterr_int(ERR_FD, -2));
  if (write(socket->fd, command, strlen(command)) == -1)
    return (puterr_int(ERR_WRITE, -1));
  return (0);
}
