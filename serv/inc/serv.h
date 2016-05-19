/*
** serv.h for serv in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 16:36:15 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 02:25:47 2016 Nyrandone Noboud-Inpeng
*/

#ifndef SERV_H_
# define SERV_H_

# define UNUSED __attribute__((unused))

# include "list.h"
# include "socket.h"

typedef struct		s_processdata
{
  int			fd;
  char			*command;
}			t_processdata;

typedef struct		s_cdata
{
  const char		*name;
  t_list		*users;
}			t_cdata;

typedef struct		s_udata
{
  int			fd;
  char			*name;
  char			*current_channel;
}			t_udata;

/*
** acceptfile.c
*/
int		accept_file(int, char *, t_list *, t_list *);

/*
** process.c
*/
int		process(t_processdata *, t_socket *,
			t_list *, t_list *);
int		checkAndProcess(fd_set *, t_socket *,
				t_list *, t_list *);

/*
** join.c
*/
int		join(int, char *, t_list *, t_list *);

/*
** list.c
*/
int		list(int, char *, t_list *, t_list *);

/*
** msg.c
*/
int		msg(int, char *, t_list *, t_list *);

/*
** management.c
*/
t_list		*addNewUser(t_socket *, t_list *);

/*
** nick.c
*/
int		nick(int, char *, t_list *, t_list *);

/*
** part.c
*/
int		part(int, char *, t_list *, t_list *);

/*
** sendfile.c
*/
int		send_file(int, char *, t_list *, t_list *);

/*
** server.c
*/
int		server(int, char *, t_list *, t_list *);

/*
** server_sockets.c
*/
t_socket	*initServerSocket();
int		getHigherFd(t_socket *, t_list *);
int		setSelectFd(t_socket *, t_list *, fd_set *);
int		close_all_sockets(t_socket *, t_list *, int);

/*
** signal.c
*/
t_socket	*saveSocket(t_socket *);
void		clean_socket();

/*
** users.c
*/
int		users(int, char *, t_list *, t_list *);

#endif /* SERV_H_ */
