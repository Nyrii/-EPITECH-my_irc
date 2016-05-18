/*
** list.c for myirc in /home/wilmot_g/Rendu/PSU_2015_myirc/common/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 16 23:49:10 2016 guillaume wilmot
** Last update Wed May 18 11:47:19 2016 guillaume wilmot
*/

#include <stdlib.h>
#include "list.h"

t_list		*get_nth_list(t_list *this, unsigned int n)
{
  t_list	*tmp;
  unsigned int	i;

  if (!this || !(tmp = *this->first))
    return (NULL);
  i = 0;
  while (tmp && i < n)
    {
      i++;
      tmp = tmp->next;
    }
  return (tmp);
}

int		push_back_list(t_list *this, void *struc)
{
  t_list	*elem;

  if (!this || !this->last || !(elem = create_list(struc, this)))
    return (-1);
  elem->prev = (*this->last);
  (*this->last)->next = elem;
  *this->last = elem;
  (*this->size)++;
  return (0);
}

int		make_circular_list(t_list *this)
{
  if (!this || !*this->first || !this->last)
    return (-1);
  (*this->last)->next = *this->first;
  (*this->first)->prev = *this->last;
  return (0);
}

t_list		*insert_at_list(t_list *this, unsigned int n, void *struc)
{
  t_list	*elem;
  t_list	*tmp;
  unsigned int	i;

  if (!this || !(tmp = *this->first) || !(elem = create_list(struc, this)))
    return (NULL);
  if (!n)
    {
      elem->next = *this->first;
      elem->prev = (*this->first)->prev;
      (*this->first)->prev ? (*this->first)->prev->next = elem : 0;
      (*this->first)->prev = elem;
      (*this->first) = elem;
      return ((*this->size)++, elem);
    }
  i = -1;
  while (tmp && ++i < n - 1)
    if (!(tmp = tmp->next))
      return (NULL);
  elem->next = tmp->next;
  elem->prev = tmp;
  tmp->next ? tmp->next->prev = elem : 0;
  tmp->next = elem;
  return ((*this->size)++, *this->first);
}

int		get_size_list(t_list *this)
{
  if (this)
    return (*this->size);
  return (-1);
}
