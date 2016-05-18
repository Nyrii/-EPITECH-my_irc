/*
** client.h for client in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:24:52 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 20:12:01 2016 Nyrandone Noboud-Inpeng
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "socket.h"

# define PACKETSIZE 128 /* A check, au moins 128 */
# define BUFSIZE ((PACKETSIZE - 33) * 100)

typedef struct		s_data
{
  char			size;
  char			name[32];
  char			message[PACKETSIZE - 33];
}			t_data;

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

#endif /* !CLIENT_H_ */
