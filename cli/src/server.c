/*
** server.c for server in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:22:26 2016 Nyrandone Noboud-Inpeng
** Last update Tue May 17 09:49:09 2016 Nyrandone Noboud-Inpeng
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "socket.h"

int		server(char *command, t_socket *socket)
{
  char		*ip;
  char		*port;

  printf("command before = %s\n", command);
    if (strtok(command, " ") == NULL)
    {
      fprintf(stderr, "Error: syntax error.\n");
      return (-2);
    }
  if ((ip = strtok(NULL, ":")) == NULL)
    {
      fprintf(stderr, "Error: cannot set the ip.\n");
      return (-2);
    }
printf("ip after = %s\n", ip);
port = strtok(NULL, "");
  if (init_socket(socket, port == NULL ? 6667 : atoi(port), "TCP",
		  inet_addr(ip)) == -1)
      return (-1);
  if (connect_socket(socket) == -1)
    return (-2);
  printf("Connected to %s:%d\n", ip, port == NULL ? 6667 : atoi(port));
  return (0);
}
