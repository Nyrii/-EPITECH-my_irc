##
## Makefile for myirc in /home/wilmot_g/Rendu/PSU_2015_myirc
##
## Made by guillaume wilmot
## Login   <wilmot_g@epitech.net>
##
## Started on  Mon May 16 23:28:34 2016 guillaume wilmot
## Last update Fri May 20 22:17:43 2016 Nyrandone Noboud-Inpeng
##

SRCCOM	= circular_buffer.c	\
	  create_list.c		\
	  create_socket.c	\
	  errors.c		\
	  get_next_line.c	\
	  list.c		\
	  pop_push.c		\
	  sockets.c

SRCSER	= acceptfile.c		\
	  delete.c		\
	  free.c		\
	  init.c		\
	  join.c		\
	  join_messages.c	\
	  list.c		\
	  main.c		\
	  management.c		\
	  msg.c			\
	  names.c		\
	  nick.c		\
	  part.c		\
	  process.c		\
	  quit.c		\
	  search_channel.c	\
	  search_user.c		\
	  sendfile.c		\
	  server_sockets.c	\
	  signal.c		\
	  users.c

SRCCLI	= acceptfile.c		\
	  client.c		\
	  join.c		\
	  list.c		\
	  main.c		\
	  msg.c			\
	  names.c		\
	  nick.c		\
	  part.c		\
	  quit.c		\
	  sendfile.c		\
	  server.c		\
	  users.c

OBJS	=  $(addprefix $(OBJSER), $(SRCSER:.c=.o))
OBJC	=  $(addprefix $(OBJCLI), $(SRCCLI:.c=.o))
OBJS	+= $(addprefix $(OBJCOM), $(SRCCOM:.c=.o))
OBJC	+= $(addprefix $(OBJCOM), $(SRCCOM:.c=.o))

RM	= rm -f

CC	= cc -g

NAMESER	= server
NAMECLI = client

OBJSER	= serv/obj/
SRCSERD	= serv/src/
INCS	= -I serv/inc/

OBJCLI	= cli/obj/
SRCCLID	= cli/src/
INCS	+= -I cli/inc/

OBJCOM	= common/obj/
SRCCOMD	= common/src/
INCS	+= -I common/inc/

COMOBJ	= common/obj
SEROBJ	= serv/obj
CLIOBJ	= cli/obj

CFLAGS	= -W -Wall -Wextra -Werror

$(OBJSER)%.o: $(SRCSERD)%.c
	@mkdir -p $(SEROBJ)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(OBJCLI)%.o: $(SRCCLID)%.c
	@mkdir -p $(CLIOBJ)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(OBJCOM)%.o: $(SRCCOMD)%.c
	@mkdir -p $(COMOBJ)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

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
