/*
** circular_buffer.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc/common/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 00:41:38 2016 guillaume wilmot
** Last update Thu May 19 15:57:52 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "circular_buffer.h"

static int	get_line_buff(t_buff *buff)
{
  int		ok;

  ok = 0;
  while (buff->end && buff->idx < PACKETSIZE)
    {
      ok = ok ? ok - 1 : ok;
      buff->cmd[buff->idx++] = buff->buff[buff->start];
      if (buff->buff[buff->start] == '\r')
	ok = 2;
      if (buff->buff[buff->start] == '\n' && ok)
	ok = 3;
      buff->start = buff->start + 1 >= PACKETSIZE * 2 ? 0 : buff->start + 1;
      buff->end--;
      if (ok == 3)
	{
	  buff->cmd[buff->idx] = 0;
	  return (0);
	}
    }
  return (-1);
}

char		*get_cmd_buff(int fd, t_buff *buff)
{
  int		cmd;

  if (!memset(buff->cmd, 0, sizeof(buff->cmd)))
    return (NULL);
  buff->back = buff->back ? buff->back : 0;
  buff->idx = 0;
  cmd = get_line_buff(buff);
  while (cmd == -1)
    {
      if (buff->idx >= PACKETSIZE)
	return (buff->cmd);
      if ((buff->end = read(fd, &buff->buff[buff->back],
			    PACKETSIZE * 2 - buff->back > PACKETSIZE ?
			    PACKETSIZE : PACKETSIZE * 2 - buff->back)) <= 0)
	return (NULL);
      buff->back = buff->back + buff->end >= PACKETSIZE * 2 ?
	buff->back + buff->end - PACKETSIZE * 2 : buff->back + buff->end;
      if (buff->end != (PACKETSIZE * 2 - buff->back > PACKETSIZE ?
      			PACKETSIZE : PACKETSIZE * 2 - buff->back))
      	buff->back = 0;
      cmd = get_line_buff(buff);
    }
  return (buff->cmd);
}

int		send_msg(int fd, char *str)
{
  unsigned int	i;
  unsigned int	len;
  int		ret;

  i = 0;
  len = strlen(str);
  while (i < len)
    {
      if ((ret = write(fd, &str[i], PACKETSIZE / 10 > len - i ?
		       len - i : PACKETSIZE / 10)) == -1)
	return (-1);
      i += ret;
    }
  return (0);
}
