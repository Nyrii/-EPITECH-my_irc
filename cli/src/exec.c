/*
** exec.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 23 16:27:27 2016 guillaume wilmot
** Last update Tue May 24 01:55:44 2016 guillaume wilmot
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "errors.h"
#include "circular_buffer.h"
#include "socket.h"

int		send_as_message(t_socket *socket, t_buffs *buffs, char *cmd)
{
  (void)socket;
  (void)cmd;
  (void)buffs;
  return (0);
}

char		*replace(char *fcmd)
{
  char		*code[12];
  char		*bis[12];
  char		*cmd;
  char		*back;
  int		i;

  init_code(code);
  init_code_bis(bis);
  if (!(back = strdup(fcmd)))
    return (puterr(ERR_MALLOC, NULL));
  if (!(cmd = strtok(back, " ")))
    return (free(back), fcmd);
  i = -1;
  while (code[++i])
    if (!strcmp(code[i], cmd))
      {
	free(back);
	cmd = &fcmd[strlen(code[i])];
	if (!(back = malloc(4097)) || !memset(back, 0, 4097) ||
	    snprintf(back, 4096, "%s%s%s\r\n", bis[i], cmd ? " " : "",
		     cmd ? cmd : "") == -1)
	  return (NULL);
	return (free(fcmd), back);
      }
  return (free(back), fcmd);
}

int		parse_cmd(char *fcmd, t_socket *socket, t_buffs *buffs)
{
  char		*code[12];
  int		(*func[12])(t_socket *, t_buffs *, char *);
  char		*cmd;
  char		*back;
  int		i;

  init_code(code);
  init_ptrfunc(func);
  if (!(back = strdup(fcmd)))
    return (puterr_int(ERR_MALLOC, -1));
  if (!(cmd = strtok(back, " ")))
    return (0);
  i = -1;
  while (code[++i])
    if (!strcmp(code[i], cmd))
      return (free(back), func[i](socket, buffs, fcmd));
  send_as_message(socket, buffs, fcmd);
  return (free(back), 0);
}
