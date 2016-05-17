/*
** list.c for list in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:23:01 2016 Nyrandone Noboud-Inpeng
** Last update Tue May 17 09:35:52 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <unistd.h>
#include "socket.h"
#include "errors.h"

int		list(char *command, t_socket *socket)
{
  if (socket->fd == -1)
    return (puterr_int(ERR_FD, -2));
  if (write(socket->fd, command, sizeof(command)) == -1)
    return (puterr_int(ERR_WRITE, -2));
  return (0);
}
