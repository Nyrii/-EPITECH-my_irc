/*
** circular_buffer.h for myIRC in /home/wilmot_g/Rendu/PSU_2015_myirc/common
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Thu May 19 00:42:04 2016 guillaume wilmot
** Last update Sat May 21 10:15:32 2016 guillaume wilmot
*/

#ifndef CIRCULAR_BUFFER_H_
# define CIRCULAR_BUFFER_H_

# define BUFFSIZE_IN	512
# define BUFFSIZE_OUT	16384

# include "list.h"

typedef struct		s_buff
{
  char			*buff;
  char			*cmd;
  unsigned int		size;
  unsigned int		idx;
  unsigned int		start;
  unsigned int		end;
  unsigned char		found;
}			t_buff;

typedef struct		s_buffs
{
  t_buff		in;
  t_buff		out;
  t_list		*cmds;
}			t_buffs;

t_buffs			*create_buffer(t_buffs *buffs);
int			get_cmd_buff(int, t_buffs *);
int			send_msg(int, char *);

#endif /* !CIRCULAR_BUFFER_H_ */
