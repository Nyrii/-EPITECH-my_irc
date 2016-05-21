/*
** list.c for list in /Users/noboud_n/Documents/Share/PSU_2015_myirc/serv/src/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Wed May 18 17:44:25 2016 Nyrandone Noboud-Inpeng
** Last update Sat May 21 23:13:23 2016 Nyrandone Noboud-Inpeng
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "serv.h"
#include "replies.h"
#include "errors.h"

int		list_all(const int fd, t_list **channels, t_list **users)
{
  char		buffer[4096];

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, RPL_LISTSTART) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  if (store_answer(get_user(*users, fd), buffer, 0) == -1)
    return (-1);

  char		*answer;
  char		*name;
  t_list	*tmp;
  int		len;
  int		i;

  answer = NULL;
  tmp = *channels;
  len = 0;
  if (tmp != NULL)
    {
      while (tmp != NULL)
	{
	  i = 0;
	  name = ((t_cdata *)(tmp->struc))->name;
	  if ((i == 0 && !(answer = malloc(10 + strlen(name))))
	      || (i != 0 && !(answer = realloc(answer,
					       len + 50 + (strlen(name) * 2)))))
	    return (puterr_int(ERR_MALLOC, -1));
	  while (RPL_LIST[i])
	    answer[len++] = RPL_LIST[i++];
	  i = 0;
	  while (name[i])
	    answer[len++] = name[i++];
  	  answer[len++] = ' ';
	  // nombre
	  answer[len++] = ' ';
	  answer[len++] = ':';
	  i = 0;
	  while (name[i])
	  tmp = tmp->next;
	}
      answer[len++] = '\r';
      answer[len++] = '\n';
      answer[len++] = '\0';
    }

  if (memset(buffer, 0, 4096) == NULL)
    return (puterr_int(ERR_MEMSET, -1));
  if (snprintf(buffer, 4096, RPL_LISTEND) == -1)
    return (puterr_int(ERR_SNPRINTF, -1));
  if (store_answer(get_user(*users, fd), buffer, 0) == -1)
    return (-1);
  return (0);
}

int		list(const int fd, char *command,
		     t_list **channels, t_list **users)
{
  if ((command = strtok(command, " ")) == NULL)
    return (list_all(fd, channels, users));
  return (0);
  // return (find_and_list(fd, channels, users, command));
}
