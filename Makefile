##
## Makefile for myirc in /home/wilmot_g/Rendu/PSU_2015_myirc
##
## Made by guillaume wilmot
## Login   <wilmot_g@epitech.net>
##
## Started on  Mon May 16 23:28:34 2016 guillaume wilmot
## Last update Wed May 18 19:31:52 2016 guillaume wilmot
##

SRCCOM	= create_list.c		\
	  create_socket.c	\
	  errors.c		\
	  get_next_line.c	\
	  list.c		\
	  pop_push.c		\
	  sockets.c

# channels.c		\
# management.c		\
# users.c

SRCSER	= main.c		\

SRCCLI	= acceptfile.c		\
	  join.c		\
	  list.c		\
	  main.c		\
	  msg.c			\
	  nick.c		\
	  part.c		\
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
