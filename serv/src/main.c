/*
** main.c for main in /Users/noboud_n/Documents/Share/PSU_2015_myirc/server/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:35:58 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 19:13:35 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include "serv.h"

int			main()
{
  t_channel		*chan;
  t_channel		*tmp;

  if ((chan = createNewChannel("A")) == NULL)
    return (-1);
  addChannel(chan, createNewChannel("B"));
  addChannel(chan, createNewChannel("C"));
  tmp = chan;
  while (tmp != NULL)
    {
      printf("name : %s\n", tmp->name);
      tmp = tmp->next;
    }
  tmp = chan;
  tmp = tmp->next;
  freeChannel(chan, "C");
  printf(" ----------- \n");
  tmp = chan;
  while (tmp != NULL)
    {
      printf("name : %s\n", tmp->name);
      tmp = tmp->next;
    }
  freeChannels(chan);
  return (0);
}
