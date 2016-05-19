/*
** main.c for main.c in /Users/noboud_n/Documents/Share/PSU_2015_myirc/client/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 11:36:21 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 20:25:32 2016 guillaume wilmot
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "errors.h"
#include "client.h"
#include "socket.h"
#include "list.h"

void		init_code(char **code)
{
  code[0] = "/server";
  code[1] = "/nick";
  code[2] = "/list";
  code[3] = "/join";
  code[4] = "/part";
  code[5] = "/users";
  code[6] = "/msg";
  code[7] = "/send_file";
  code[8] = "/accept_file";
  code[9] = NULL;
}

void		init_ptrfunc(int (**func)(char *, t_socket *))
{
  func[0] = &server;
  func[1] = &nick;
  func[2] = &list;
  func[3] = &join;
  func[4] = &part;
  func[5] = &users;
  func[6] = &msg;
  func[7] = &send_file;
  func[8] = &accept_file;
  func[9] = NULL;
}

int		main()
{
  // char		*command;
  // int		i;
  // int		ret;

  // char		*code[10];
  // int		(*func[10])(char *, t_socket *);
  // fd_set	readf;
  // t_socket	*socket;
  // char		buffer[4096];

  // init_code(code);
  // init_ptrfunc(func);
  // if ((socket = create_socket()) == NULL)
  //   return (-1);
  // while (1)
  //   {
  //     FD_ZERO(&readf);
  //     if (socket->fd != -1)
  // D_SET(socket->fd, &readf);
  //     FD_SET(0, &readf);
  //     if (select(socket->fd != -1 ? socket->fd + 1 : 1,
  //  &readf, NULL, NULL, NULL) == -1)
  // eturn (puterr_int("Error: select failed.\n", -1));
  //     if (FD_ISSET(socket->fd, &readf))
  //
  //
  //
  //     else if (FD_ISSET(0, &readf))
  //
  //  read(0, buffer, 4096);
  //  printf("waiting...\n");
  //
  //   }



  // while ((buffer = get_next_line(0)))
  //   {
  //     ret = 9999;
  //     i = -1;
  //     if ((command = strtok(buffer, " ")) == NULL)
  // uterr_int(ERR_SYNTAX, -1);
  //     else
  //
  //  while (code[++i] != NULL)
  //    {
  //      if (!strcmp(code[i], command))
  // {
  //   if ((ret = func[i](strtok(buffer, ""), socket)) == -1)
  //     return (socket->fd != -1 ? close_socket(socket) : -1);
  // }
  //    }
  //  if (ret == 9999)
  //    puterr_int(ERR_SYNTAX, -1);
  //
  //     buffer ? free(buffer) : 0;
  //   }

  t_list	*tmp;
  t_data	data;
  int		i;

  if (memset(&data, 0, PACKETSIZE) == NULL)
    return (puterr_int(ERR_MEMSET, -1));

  i = 0;
  if ((tmp = create_list(&data, NULL)) == NULL)
    return (-1);
  while (i < BUFSIZE - 1)
    {
      if (push_back_list(tmp, &data) == NULL)
	return (-1);
      ++i;
    }
  while (tmp != NULL)
    {
      // printf("tmp->isFree = %d\n", ((t_data *)(tmp->struc))->is_free);
      // printf("tmp->message = %s\n", ((t_data *)(tmp->struc))->message);
      printf("\n");
      tmp = tmp->next;
    }

  return (0);
}
