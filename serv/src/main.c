/*
** main.c for main in /Users/noboud_n/Documents/Share/PSU_2015_myirc/server/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:35:58 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 12:01:38 2016 guillaume wilmot
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "circular_buffer.h"
#include "errors.h"
#include "serv.h"

int			main()
{
  /* int			fd; */
  /* t_buff		buff; */

  /* if (memset(&buff, 0, sizeof(t_buff)) == NULL) */
  /*   return (puterr_int("Memset fail", -1)); */
  /* if ((fd = open("./test", O_RDONLY)) == -1) */
  /*   return (puterr_int("Open fail", -1)); */
  /* while (1) */
  /*   if (get_cmd_buff(fd, &buff)) */
  /*     fprintf(stderr, "cmd : %s", buff.cmd); */
  /*   else */
  /*     return (0); */
  t_socket		*socket;

  signal(SIGINT, clean_socket);
  if ((socket = initServerSocket()) == NULL)
    return (-1);
  core(socket, NULL, NULL);
  return (0);
}
