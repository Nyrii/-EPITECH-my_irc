/*
** circularbuffer.c for circularbuffer in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 11:25:25 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 13:19:17 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include "errors.h"
#include "client.h"

#include <stdio.h>
// int			countElements(t_circular *template)
// {
//   t_circular		*tmp;
//   int			i;
//
//   tmp = template;
//   i = 0;
//   if (tmp->next == tmp)
//     return (1);
//   while (tmp != tmp->end)
//     {
//       ++i;
//       tmp = tmp->next;
//     }
//   return (++i);
// }
//
// t_circular		*createFirstNode(char *message)
// {
//   t_circular		*tmp;
//
//   if ((tmp = malloc(sizeof(t_circular))) == NULL)
//     return (puterr(ERR_MALLOC, NULL));
//   tmp->next = tmp;
//   tmp->prev = tmp;
//   tmp->message = message;
//   tmp->start = tmp;
//   tmp->end = tmp;
//   return (tmp);
// }
//
// int			circularInsert(t_circular *template, char *message)
// {
//   t_circular		*tmp;
//   t_circular		*to_insert;
//   int			count;
//
//   tmp = template;
//   count = countElements(template);
//   if (count == 1)
//     {
//       if ((to_insert = malloc(sizeof(t_circular))) == NULL)
// 	return (puterr_int(ERR_MALLOC, -1));
//       to_insert->message = message;
//       tmp->end = to_insert;
//       to_insert->end = to_insert;
//       to_insert->start = tmp;
//       to_insert->next = tmp;
//       tmp->next = to_insert;
//       to_insert->prev = tmp;
//       tmp->prev = to_insert;
//     }
//   else if (count != BUFSIZE)
//     {
//       if ((to_insert = malloc(sizeof(t_circular))) == NULL)
// 	return (puterr_int(ERR_MALLOC, -1));
//       to_insert->message = message;
//       while (tmp->role != END)
// 	tmp = tmp->prev;
//       tmp->next->prev = to_insert;
//       to_insert->prev = tmp;
//       to_insert->next = tmp->next;
//       tmp->next = to_insert;
//       to_insert->role = END;
//       tmp->role = NONE;
//     }
//   else
//     {
//
//     }
//   return (0);
// }
