##
## Makefile for minitalk in /media/blinux/noboud_n/rendu/PSU_2014_minitalk
##
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
##
## Started on  Mon Feb 23 11:58:39 2015 Nyrandone Noboud-Inpeng
## Last update Mon May 16 23:30:50 2016 Nyrandone Noboud-Inpeng
##

SRCSER	= channels.c	\
	  main.c	\
	  management.c	\
	  users.c

SRCCLI	= acceptfile.c		\
	  get_next_line.c	\
	  join.c		\
	  list.c		\
	  main.c		\
	  msg.c			\
	  nick.c		\
	  part.c		\
	  sendfile.c		\
	  server.c		\
	  users.c

OBJS	= $(addprefix $(OBJSER), $(SRCSER:.c=.o))
OBJC	= $(addprefix $(OBJCLI), $(SRCCLI:.c=.o))

RM	= rm -f

CC	= cc -g

NAMESER	= server
NAMECLI = client

OBJSER	= serv/obj/
SRCSERD	= serv/src/
INCSER	= -I serv/inc/

OBJCLI	= cli/obj/
SRCCLID	= cli/src/
INCCLI	= -I cli/inc/

SEROBJ	= serv/obj
CLIOBJ	= cli/obj

CFLAGS	= -W -Wall -Wextra -Werror

$(OBJSER)%.o: $(SRCSERD)%.c
	@mkdir -p $(SEROBJ)
	$(CC) $(CFLAGS) $(INCSER) -o $@ -c $<

$(OBJCLI)%.o: $(SRCCLID)%.c
	@mkdir -p $(CLIOBJ)
	$(CC) $(CFLAGS) $(INCCLI) -o $@ -c $<

all:
	@make --no-print-directory $(NAMESER)
	@make --no-print-directory $(NAMECLI)

$(NAMESER): $(OBJS)
	$(CC) -o $(NAMESER) $(CFLAGS) $(OBJS)

$(NAMECLI): $(OBJC)
	$(CC) -o $(NAMECLI) $(CFLAGS) $(OBJC)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJC)

fclean: clean
	$(RM) $(NAMESER)
	$(RM) $(NAMECLI)

re: fclean all
