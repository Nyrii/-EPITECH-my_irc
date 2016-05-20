/*
** client.h for client in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:24:52 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 18:40:36 2016 guillaume wilmot
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "socket.h"

int		wait_for_input(t_socket *socket, char **code,
                               int (**func)(char *, t_socket *));

/*
** acceptfile.c
*/
int		accept_file(char *, t_socket *);

/*
** circularbuffer.c
*/
// t_circular	*createFirstNode(char *);
// int		circularInsert(t_circular *, char *);

/*
** get_next_line.c
*/
char		*get_next_line(const int);

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
int		send_file(char *, t_socket *);

/*
** server.c
*/
int		server(char *, t_socket *);

/*
** users.c
*/
int		users(char *, t_socket *);

/*
** names.c
*/
int		names(char *, t_socket *);

/*
** quit.c
*/
int		quit(char *, t_socket *);

#endif /* !CLIENT_H_ */
