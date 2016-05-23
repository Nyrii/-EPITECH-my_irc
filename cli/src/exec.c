/*
** exec.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 23 16:27:27 2016 guillaume wilmot
** Last update Mon May 23 18:35:31 2016 guillaume wilmot
*/

#include "client.h"
#include "circular_buffer.h"
#include "socket.h"

int		replace(t_socker *socket, t_buffs *buffs, char *cmd)
{

}

int		parse_cmd(char *fcmd, t_socket *socket, t_buffs *buffs)
{
  static char	*code[12] = NULL;
  static int	(*func[12])(char *, t_socket *) = NULL;
  char		*cmd;
  char		*back;
  int		i;

  !code ? init_code(code) : 0;
  !func ? init_ptrfunc(func) : 0;
  if (!(back = strdup(cmd)))
    return (puterr_int(ERR_MALLOC, -1));
  if (!(cmd = strtok(back, " ")))
    return (0);
  i = -1;
  while (code[++i])
    if (!strcmp(code[i], cmd))
      return (free(back), func[i](socket, buffs, strtok(NULL, "")) == -1);
  send_as_message(socket, buffs);
  return (free(bakc), 0);
}
