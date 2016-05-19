/*
** main.c for main in /Users/noboud_n/Documents/Share/PSU_2015_myirc/server/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:35:58 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:33:19 2016 Nyrandone Noboud-Inpeng
*/

#include <stdlib.h>
#include <signal.h>
#include "serv.h"

int			main()
{
  t_socket		*socket;

  signal(SIGINT, clean_socket);
  if ((socket = initServerSocket()) == NULL)
    return (-1);
  core(socket, NULL, NULL);
  return (0);
}
