/*
** serv.h for serv in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 16:36:15 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 19:18:12 2016 Nyrandone Noboud-Inpeng
*/

#ifndef SERV_H_
# define SERV_H_

typedef struct		s_users
{
  int			fd;
  char			*name;
  char			*channelname;
  struct s_users	*next;
}			t_users;

typedef struct		s_channel
{
  const char		*name;
  t_users		*users;
  struct s_channel	*next;
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

#endif /* SERV_H_ */
