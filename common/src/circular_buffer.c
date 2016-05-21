/*
** circular_buffer.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc/common/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 00:41:38 2016 guillaume wilmot
** Last update Sat May 21 02:30:08 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "errors.h"

t_buffs		*create_buffer(t_buffs *buffs)
{
  if (!memset(&buffs->in, 0, sizeof(t_buff)) ||
      !memset(&buffs->out, 0, sizeof(t_buff)) ||
      !(buffs->in.buff = malloc(BUFFSIZE_IN * sizeof(char))) ||
      !(buffs->in.cmd = malloc(BUFFSIZE_IN * sizeof(char))) ||
      !(buffs->out.buff = malloc(BUFFSIZE_OUT * sizeof(char))) ||
      !(buffs->out.cmd = malloc(BUFFSIZE_OUT * sizeof(char))) ||
      !memset(buffs->in.buff, 0, BUFFSIZE_IN) ||
      !memset(buffs->in.cmd, 0, BUFFSIZE_IN) ||
      !memset(buffs->out.buff, 0, BUFFSIZE_OUT) ||
      !memset(buffs->out.cmd, 0, BUFFSIZE_OUT))
    return (puterr(ERR_MALLOC, NULL));
  buffs->in.size = BUFFSIZE_IN;
  buffs->out.size = BUFFSIZE_OUT;
  return (buffs);
}

int		write_to_buffer(char *str, t_buff *buff, int size)
{
  unsigned int	go;
  int		i;

  i = -1;
  go = buff->start == buff->end ? 1 : 0;
  while (++i < size && ((buff->start + i) % buff->size != buff->end || go))
    buff->buff[(buff->start + i) % buff->size] = str[i];
  if ((buff->start + i) % buff->size == buff->end && (!go || i) && i != size)
    return (-1);
  buff->end = (buff->end + i) % buff->size;
  return (0);
}

char		*get_next_cmd(t_buff *buff)
{
  char		*cmd;
  unsigned int	start;

  start = buff->start;
  while ((start + buff->idx) % buff->size != buff->end)
    {
      buff->found = buff->found ? buff->found - 1 : buff->found;
      buff->cmd[buff->idx] = buff->buff[buff->start];
      buff->buff[buff->start] = 0;
      buff->found =  buff->cmd[buff->idx] == '\r' ? buff->found : 2;
      if (buff->cmd[buff->idx] == '\n' && buff->found)
	buff->found = 3;
      buff->idx = (buff->idx + 1) % buff->size;
      buff->start = (buff->start + 1) % buff->size;
      if (buff->found == 3)
	{
	  if (!(cmd = strdup(buff->cmd)) ||
	      !memset(buff->cmd, 0, buff->size))
	    return (NULL);
	  buff->idx = 0;
	  buff->found = 0;
	  return (cmd);
	}
    }
  return (NULL);
}

int		get_cmd_buff(int fd, t_buff *buff)
{
  char		tmp[buff->size];
  char		*cmd;
  int		ret;

  if ((ret = read(fd, tmp, buff->size)) <= 0 ||
      write_to_buffer(tmp, buff, ret) == -1)
    return (-1);
  while ((cmd = get_next_cmd(buff)))
    printf("%s\n", cmd);
  printf("buff->start %d buff->end %d\n", buff->start, buff->end);
  return (0);
}
