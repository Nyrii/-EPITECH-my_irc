/*
** serv.h for serv in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 16:36:15 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 20:20:44 2016 guillaume wilmot
*/

#ifndef SERV_H_
# define SERV_H_

# define UNUSED __attribute__((unused))

# include "list.h"

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
** users.c
*/
int		users(int, char *, t_list *, t_list *);

#endif /* SERV_H_ */
