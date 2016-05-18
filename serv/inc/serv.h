/*
** serv.h for serv in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 16:36:15 2016 Nyrandone Noboud-Inpeng
** Last update Wed May 18 13:20:54 2016 guillaume wilmot
*/

#ifndef SERV_H_
# define SERV_H_

# include "list.h"

typedef struct		s_users
{
  int			fd;
  char			*name;
  char			*channelname;
}			t_users;

typedef struct		s_channel
{
  const char		*name;
  t_list		*users;
}			t_channel;

/*
** channels.c
*/
t_channel		*createNewChannel(const char *);
int			addChannel(t_channel *, t_channel *);
void			freeChannel(t_channel *, const char *);
void			freeChannels(t_channel *);

/*
** management.c
*/
int			addUserToChannel(t_channel *, t_users *);
int			removeUserFromChannel(t_channel *, const char *);

/*
** users.c
*/
void			removeUser(t_users *, const char *);
void			freeUsers(t_users *);

#endif /* SERV_H_ */
