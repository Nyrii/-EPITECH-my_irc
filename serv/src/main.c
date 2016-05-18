/*
** main.c for main in /Users/noboud_n/Documents/Share/PSU_2015_myirc/server/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:35:58 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 11:45:48 2016 guillaume wilmot
*/

#include <stdio.h>
#include "errors.h"
#include "serv.h"
#include "list.h"

int			main()
{
  int			i;
  t_list		*list;

  if (!(list = create_list(NULL, NULL)))
    return (-1);
  list->push_back(list, NULL);
  list->push_back(list, NULL);
  list->push_back(list, NULL);
  list->push_back(list, NULL);
  printf("Size : %d\n", list->get_size(list));
  list->push_back(list, NULL);
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  list->make_circular(list);
  puts("Making it circular");
  for (i = 0; i < list->get_size(list) * 2; i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  puts("delete first");
  if (!(list = list->delete_nth(list, 0)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  puts("delete second");
  if (!(list = list->delete_nth(list, 1)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  puts("insert at 0");
  if (!(list = list->insert_at(list, 0, NULL)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  puts("insert at 1");
  if (!(list = list->insert_at(list, 1, NULL)))
    return (puterr_int("Error\n", -1));
  printf("Size : %d\n", list->get_size(list));
  for (i = 0; i < list->get_size(list); i++)
    printf("id : %d\n", list->get_nth(list, i) ? (int)list->get_nth(list, i)->id : -1);
  list->destroy(list);
  /* t_channel		*chan; */
  /* t_channel		*tmp; */

  /* if ((chan = createNewChannel("A")) == NULL) */
  /*   return (-1); */
  /* addChannel(chan, createNewChannel("B")); */
  /* addChannel(chan, createNewChannel("C")); */
  /* tmp = chan; */
  /* while (tmp != NULL) */
  /*   { */
  /*     printf("name : %s\n", tmp->name); */
  /*     tmp = tmp->next; */
  /*   } */
  /* tmp = chan; */
  /* tmp = tmp->next; */
  /* freeChannel(chan, "C"); */
  /* printf(" ----------- \n"); */
  /* tmp = chan; */
  /* while (tmp != NULL) */
  /*   { */
  /*     printf("name : %s\n", tmp->name); */
  /*     tmp = tmp->next; */
  /*   } */
  /* freeChannels(chan); */
  return (0);
}
