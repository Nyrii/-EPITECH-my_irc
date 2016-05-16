/*
** client.h for client in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:24:52 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 23:54:38 2016 Nyrandone Noboud-Inpeng
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "socket.h"

/*
** get_next_line.c
*/
char		*get_next_line(const int);

/*
** acceptfile.c
*/
int		acceptfile(char *, t_socket *);

/*
** join.c
*/
int		join(char *, t_socket *);

/*
** list.c
*/
int		list(char *, t_socket *);

/*
** msg.c
*/
int		msg(char *, t_socket *);

/*
** nick.c
*/
int		nick(char *, t_socket *);

/*
** part.c
*/
int		part(char *, t_socket *);

/*
** sendfile.c
*/
int		sendfile(char *, t_socket *);

/*
** server.c
*/
int		server(char *, t_socket *);

/*
** users.c
*/
int		users(char *, t_socket *);

#endif /* !CLIENT_H_ */
