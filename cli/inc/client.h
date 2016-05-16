/*
** client.h for client in /Users/noboud_n/Documents/Share/PSU_2015_myirc/cli/inc/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon May 16 23:24:52 2016 Nyrandone Noboud-Inpeng
** Last update Mon May 16 23:28:14 2016 Nyrandone Noboud-Inpeng
*/

#ifndef CLIENT_H_
# define CLIENT_H_

/*
** get_next_line.c
*/
char		*get_next_line(const int);

/*
** acceptfile.c
*/
int		acceptfile();

/*
** join.c
*/
int		join();

/*
** list.c
*/
int		list();

/*
** msg.c
*/
int		msg();

/*
** nick.c
*/
int		nick();

/*
** part.c
*/
int		part();

/*
** sendfile.c
*/
int		sendfile();

/*
** server.c
*/
int		server();

/*
** users.c
*/
int		users();

#endif /* !CLIENT_H_ */
