/*
** errors.h for myftp in /home/wilmot_g/Rendu/PSU_2015_myftp
**
** Made by guillaume wilmot
** Login   <wilmot_g@epitech.net>
**
** Started on  Mon May  2 11:18:44 2016 guillaume wilmot
** Last update Tue May 17 01:08:08 2016 Nyrandone Noboud-Inpeng
*/

#ifndef ERRORS_H_
# define ERRORS_H_

# define ERR_MALLOC		"Error: malloc failed\n"
# define ERR_GETPROTOBYNAME	"Error: getprotobyname failed\n"
# define ERR_SOCKET		"Error: socket failed\n"
# define ERR_CLOSE		"Error: close failed\n"
# define ERR_BIND		"Error: bind failed\n"
# define ERR_ACCEPT		"Error: accept failed\n"
# define ERR_CONNECT		"Error: connect failed\n"
# define ERR_LISTEN		"Error: listen failed\n"
# define ERR_READ		"Error: read failed\n"
# define ERR_WRITE		"Error: write failed\n"
# define ERR_FORK		"Error: fork failed\n"
# define ERR_CHDIR		"Error: chdir failed\n"
# define ERR_GETCWD		"Error: getcwd failed\n"
# define ERR_OPEN		"Error: open failed\n"
# define ERR_STAT		"Error: stat failed\n"
# define ERR_SENDFILE		"Error: sendfile failed\n"
# define ERR_MEMSET		"Error: memset failed\n"
# define ERR_FD			"Error: aborted an action. (fd not set)\n"

int		puterr_int(const char *, int);
void		*puterr(const char *, void *);

#endif /* !ERRORS_H_ */
