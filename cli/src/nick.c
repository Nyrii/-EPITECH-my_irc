/*
** nick.c for nick in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:22:48 2016 Nyrandone Noboud-Inpeng
** Last update Tue May 24 00:45:30 2016 guillaume wilmot
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "socket.h"
#include "errors.h"
#include "client.h"

int		nick(t_socket *socket, t_buffs *buffs, char *cmd)
{
  (void)socket;
  if (!(cmd = replace(cmd)))
    return (-1);
  if (write_to_buffer(cmd, &buffs->out, strlen(cmd)) == -1)
    return (puterr_int("Error: message too long", -2));
  return (0);
}
