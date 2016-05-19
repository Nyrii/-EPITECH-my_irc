/*
** serv.h for serv in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 16:36:15 2016 Nyrandone Noboud-Inpeng
** Last update Thu May 19 21:39:45 2016 Nyrandone Noboud-Inpeng
*/

#ifndef SERV_H_
# define SERV_H_

# define UNUSED __attribute__((unused))

# include "list.h"
# include "socket.h"
# include "circular_buffer.h"

typedef struct		s_processdata
{
  int			fd;
  char			*command;
}			t_processdata;

typedef struct		s_cdata
{
  char			*name;
  t_list		*users;
}			t_cdata;

typedef struct		s_udata
{
  int			fd;
  char			*name;
  char			*current_channel;
  t_buff		buff;
}			t_udata;

/*
** acceptfile.c
*/
int		accept_file(const int, char *, t_list **, t_list *);

/*
** init.c
*/
void		init_code(char **);
void		init_ptrfunc(int (**)(const int, char *,
				      t_list **, t_list *));

/*
** join.c
*/
int		join(const int, char *, t_list **, t_list *);

/*
** join_messages.c
*/
int		joinSucceed(const int, t_list *);
int		alreadyInChannel(const int, t_list *);

/*
** list.c
*/
int		list(const int, char *, t_list **, t_list *);

/*
** msg.c
*/
int		msg(const int, char *, t_list **, t_list *);

/*
** management.c
*/
t_list		*getUser(t_list *, const int);
char		*getUserName(t_list *, const int);
t_list		*addNewUser(t_socket *, t_list *);

/*
** nick.c
*/
int		nick(const int, char *, t_list **, t_list *);

/*
** part.c
*/
int		part(const int, char *, t_list **, t_list *);

/*
** process.c
*/
int		core(t_socket *, t_list *, t_list *);

/*
** search_channel.c
*/
t_list		*searchChannelByName(t_list *, const char *);
int		searchChannelByUserFd(t_list *, const int);

/*
** search_user.c
*/
t_list		*getUser(t_list *, const int);
char		*getUserName(t_list *, const int);

/*
** sendfile.c
*/
int		send_file(const int, char *, t_list **, t_list *);

/*
** server.c
*/
int		server(const int, char *, t_list **, t_list *);

/*
** server_sockets.c
*/
int		answerClient(int, const char *, int);
t_socket	*initServerSocket();
int		getHigherFd(t_socket *, t_list *);
int		setSelectFd(t_socket *, t_list *, fd_set *);
int		closeAndFree(t_socket *, t_list *, t_list *, int);

/*
** signal.c
*/
t_socket	*saveSocket(t_socket *);
t_list		*saveUsers(t_list *);
t_list		*saveChannels(t_list *);
void		clean_socket();

/*
** users.c
*/
int		users(const int, char *, t_list **, t_list *);

#endif /* SERV_H_ */
