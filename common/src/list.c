/*
** list.c for myirc in /home/wilmot_g/Rendu/PSU_2015_myirc/common/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 16 23:49:10 2016 guillaume wilmot
** Last update Tue May 17 01:18:26 2016 guillaume wilmot
*/

#include <stdlib.h>
#include "list.h"

t_list		*get_nth_list(t_list *this, unsigned int n)
{
  t_list	*tmp;
  t_list	*back;;
  unsigned int	i;
  unsigned int	circle;

  if (!this || !(tmp = this->first))
    return (NULL);
  i = 0;
  circle = 0;
  back = tmp;
  while (tmp && i < n && (tmp != back || !circle))
    {
      i++;
      circle = 1;
      tmp = tmp->next;
    }
  if (tmp != back)
    return (tmp);
  return (NULL);
}

int		push_back_list(t_list *this, void *struc)
{
  t_list	*elem;

  if (!this || !this->last || !(elem = create_list()))
    return (-1);
  elem->struc = struc;
  elem->id = this->last->id + 1;
  elem->first = this->first;
  elem->last = this->last;
  this->last->next = elem;
  this->last = elem;
  (*this->size)++;
  return (0);
}

int		make_circular_list(t_list *this)
{
  if (!this || !this->first || !this->last)
    return (-1);
  this->last->next = this->first;
  this->first->prev = this->last;
  return (0);
}

int		delete_nth_list(t_list *this, unsigned int n)
{
  t_list	*tmp;
  t_list	*back;;
  unsigned int	i;
  unsigned int	circle;

  if (!this || !(tmp = this->first))
    return (-1);
  i = 0;
  circle = 0;
  back = tmp;
  while (tmp && i < n && (tmp != back || !circle))
    {
      i++;
      circle = 1;
      tmp = tmp->next;
    }
  if (tmp != back)
    {
      free(tmp->struc);
      free(tmp);
    }
  else
    return (-1);
  (*this->size)--;
  return (0);
}

int		get_size_list(t_list *this)
{
  if (this)
    return (*this->size);
  return (-1);
}
