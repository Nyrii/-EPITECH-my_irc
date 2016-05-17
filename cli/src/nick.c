/*
** nick.c for nick in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:22:48 2016 Nyrandone Noboud-Inpeng
** Last update Tue May 17 09:36:01 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <unistd.h>
#include "socket.h"
#include "errors.h"

int		nick(char *command, t_socket *socket)
{
  if (socket->fd == -1)
    return (puterr_int(ERR_FD, -2));
  if (write(socket->fd, command, sizeof(command)) == -1)
    return (puterr_int(ERR_WRITE, -2));
  return (0);
}
