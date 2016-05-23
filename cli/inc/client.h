/*
** client.h for client in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:24:52 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 23 22:10:21 2016 guillaume wilmot
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "circular_buffer.h"
# include "socket.h"

/*
** acceptfile.c
*/
int		accept_file(t_socket *, t_buffs *, char *);

/*
** client.c
*/
int		wait_for_input(t_socket *);

/*
** exec.c
*/
int		parse_cmd(char *, t_socket *, t_buffs *);
char		*replace(char *);

/*
** get_next_line.c
*/
char		*get_next_line(const int);

/*
** join.c
*/
int		join(t_socket *, t_buffs *, char *);

/*
** list.c
*/
int		list(t_socket *, t_buffs *, char *);

/*
** main.c
*/
void		init_code_bis(char **);
void		init_code(char **);
void		init_ptrfunc(int (**)(t_socket *, t_buffs *, char *));

/*
** msg.c
*/
int		msg(t_socket *, t_buffs *, char *);

/*
** nick.c
*/
int		nick(t_socket *, t_buffs *, char *);

/*
** part.c
*/
int		part(t_socket *, t_buffs *, char *);

/*
** sendfile.c
*/
int		send_file(t_socket *, t_buffs *, char *);

/*
** server.c
*/
int		server(t_socket *, t_buffs *, char *);

/*
** users.c
*/
int		users(t_socket *, t_buffs *, char *);

/*
** names.c
*/
int		names(t_socket *, t_buffs *, char *);

/*
** quit.c
*/
int		quit(t_socket *, t_buffs *, char *);

#endif /* !CLIENT_H_ */
