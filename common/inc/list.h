/*
** list.h for list in /home/wilmot_g/Rendu/PSU_2015_myirc/common/inc
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 16 23:51:11 2016 guillaume wilmot
** Last update Tue May 17 01:17:20 2016 guillaume wilmot
*/

#ifndef LIST_H_
# define LIST_H_

#include <netdb.h>

typedef struct		s_list
{
  struct s_list		*first;
  struct s_list		*last;
  struct s_list		*next;
  struct s_list		*prev;
  void			*struc;
  unsigned int		*size;
  unsigned int		id;
  struct s_list		*(*create)();
  struct s_list		*(*get_nth)(struct s_list *, unsigned int);
  int			(*push_back)(struct s_list *, void *);
  int			(*make_circular)(struct s_list *);
  int			(*delete_nth)(struct s_list *, unsigned int);
  int			(*get_size)(struct s_list *);
  void			(*destroy)(struct s_list *);
}			t_list;

t_list			*create_list();
t_list			*get_nth_list(t_list *, unsigned int);
int			push_back_list(t_list *, void *);
int			make_circular_list(t_list *);
int			delete_nth_list(t_list *, unsigned int);
int			get_size_list(t_list *);
void			destroy_list(t_list *);

#endif /* !LIST_H_ */
