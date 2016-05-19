/*
** main.c for main in /Users/noboud_n/Documents/Share/PSU_2015_myirc/server/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:35:58 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:25:16 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "errors.h"
#include "serv.h"
#include "list.h"

int			main()
{
  // char			buffer[4096];
  t_list		*channels;
  t_list		*users;
  t_socket		*socket;
  fd_set		readf;

  channels = NULL;
  users = NULL;
  signal(SIGINT, clean_socket);
  if ((socket = initServerSocket()) == NULL)
    return (-1);
  (void)channels;
  while (1)
    {
      FD_ZERO(&readf);
      setSelectFd(socket, users, &readf);
      if (select(getHigherFd(socket, users) + 1,
		 &readf, NULL, NULL, NULL) == -1)
	return (puterr_int("Error: select failed.\n", -1));
      if (FD_ISSET(socket->fd, &readf))
	{
	  if ((users = addNewUser(socket, users)) == NULL)
	    return (close_all_sockets(socket, users, -1));
	  /**/
	  t_list	*tmp = users;

	  while (tmp != NULL)
	    {
	      printf("tmp->fd = %d\n", ((t_udata *)(tmp->struc))->fd);
	      tmp = tmp->next;
	    }
	  /**/
	}
      if (checkAndProcess(&readf, socket, channels, users) == -1)
	return (-1);
    }
  return (0);
}
