/*
** list.c for myirc in /home/wilmot_g/Rendu/PSU_2015_myirc/common/src
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May 16 23:49:10 2016 guillaume wilmot
** Last update Tue May 17 01:16:36 2016 guillaume wilmot
*/

#include <stdlib.h>
#include "errors.h"
#include "list.h"

t_list		*create_list()
{
  t_list	*list;

  if (!(list = malloc(sizeof(*list))) ||
      !(list->size = malloc(sizeof(unsigned int))))
    return (puterr(ERR_MALLOC, NULL));
  list->first = list;
  list->last = list;
  list->struc = NULL;
  list->next = NULL;
  list->prev = NULL;
  *list->size = 0;
  list->id = 1;
  list->create = &create_list;
  list->push_back = &push_back_list;
  list->make_circular = &make_circular_list;
  list->destroy = &destroy_list;
  list->get_nth = &get_nth_list;
  list->delete_nth = &delete_nth_list;
  list->get_size = &get_size_list;
  return (list);
}

void		destroy_list(t_list *this)
{
  t_list	*tmp;

  if (!this || !this->last)
    return ;
  while (this != NULL)
    {
      tmp = this;
      this = this->next;
      free(tmp);
    }
}
