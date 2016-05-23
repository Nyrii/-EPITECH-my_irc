/*
** client.h for client in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:24:52 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 23 16:46:02 2016 guillaume wilmot
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "circular_buffer.h"
# include "socket.h"

/*
** acceptfile.c
*/
int		accept_file(char *, t_socket *);

/*
** client.c
*/
int		wait_for_input(t_socket *);

/*
** exec.c
*/
int		parse_cmd(char *, t_socket *, t_buffs *);

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
** main.c
*/
void		init_code(char **);
void		init_ptrfunc(int (**)(char *, t_socket *));

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
