/*
** circular_buffer.c for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc/common/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 00:41:38 2016 guillaume wilmot
** Last update Sat May 21 18:36:38 2016 guillaume wilmot
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "circular_buffer.h"
#include "errors.h"

static void		replace_end_of_string(char *string)
{
  int			i;

  if (!string)
    return ;
  i = strlen(string);
  if (i > 1 && string[i - 1] == '\n' && string[i - 2] == '\r')
    {
      string[i - 2] = '\0';
      string[i - 1] = '\0';
    }
}

t_buffs		*create_buffer(t_buffs *buffs)
{
  if (!memset(buffs, 0, sizeof(t_buffs)) ||
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
	  cmd = malloc(1024);
	  memset(cmd, 0, 1024);
	  strcat(cmd, buff->cmd);
	    /* strdup(buff->cmd); */
	  if (!memset(buff->cmd, 0, buff->size))
	    return (NULL);
	  buff->idx = 0;
	  buff->found = 0;
	  return (cmd);
	}
    }
  return (NULL);
}

int		get_cmd_buff(int fd, t_buffs *buffs)
{
  char		tmp[buffs->in.size];
  char		*cmd;
  int		ret;

  buffs->cmds ? free_content(buffs->cmds) : 0;
  buffs->cmds ? buffs->cmds->destroy(buffs->cmds) : 0;
  buffs->cmds = NULL;
  if ((ret = read(fd, tmp, buffs->in.size)) <= 0)
    return (!(buffs->cmds = create_list(strdup("QUIT"), NULL)) ? -1 : -3);
  if (write_to_buffer(tmp, &buffs->in, ret) == -1)
    return (-2);
  while ((cmd = get_next_cmd(&buffs->in)))
    {
      replace_end_of_string(cmd);
      if ((!buffs->cmds && !(buffs->cmds = create_list(cmd, NULL))) ||
	  !(buffs->cmds = buffs->cmds->push_back(buffs->cmds, cmd)))
	return (-1);
      if (!strcmp("QUIT", cmd) || !strncmp(cmd, "QUIT ", 5))
	return (-3);
      printf("CMD : %p %s\n", cmd, cmd);
    }
  return (0);
}
