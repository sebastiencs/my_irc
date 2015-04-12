
NAME		= myirc

server		= server

client		= client

DIR_SERVER	= ./src/server

DIR_CLIENT	= ./src/client

DIR_COMMON	= ./src/common

SRC_SERVER	= $(DIR_SERVER)/server.c		\
		  $(DIR_SERVER)/create_server.c		\
		  $(DIR_SERVER)/list_clients.c		\
		  $(DIR_SERVER)/list_buffer.c		\
		  $(DIR_SERVER)/loop_server.c		\
		  $(DIR_SERVER)/add_client.c		\
		  $(DIR_SERVER)/set_user.c		\
		  $(DIR_SERVER)/reply.c			\
		  $(DIR_SERVER)/list_chan.c		\
		  $(DIR_SERVER)/join_chan.c		\
		  $(DIR_SERVER)/ping_pong.c		\
		  $(DIR_SERVER)/names.c			\
		  $(DIR_SERVER)/part_chan.c		\
		  $(DIR_SERVER)/clean_telnet.c		\
		  $(DIR_SERVER)/free_client.c		\
		  $(DIR_SERVER)/priv_msg.c		\
		  $(DIR_SERVER)/list_channel.c		\
		  $(DIR_SERVER)/set_nickname.c		\
		  $(DIR_SERVER)/init_select.c		\
		  $(DIR_SERVER)/interpret_command.c	\
		  $(DIR_SERVER)/get_port.c

SRC_CLIENT	= $(DIR_CLIENT)/client.c		\
		  $(DIR_CLIENT)/nick_function.c		\
		  $(DIR_CLIENT)/private_function.c	\
		  $(DIR_CLIENT)/join_function.c		\
		  $(DIR_CLIENT)/list_function.c		\
		  $(DIR_CLIENT)/read_cmd.c		\
		  $(DIR_CLIENT)/read_server.c		\
		  $(DIR_CLIENT)/write_server.c		\
		  $(DIR_CLIENT)/send_part.c		\
		  $(DIR_CLIENT)/user_function.c		\
		  $(DIR_CLIENT)/loop_client.c		\
		  $(DIR_CLIENT)/server_function.c       \
		  $(DIR_CLIENT)/chan_message.c		\
		  $(DIR_CLIENT)/switch_chan.c

SRC_COMMON	= $(DIR_COMMON)/derror.c		\
		  $(DIR_COMMON)/puts_telnet.c		\
		  $(DIR_COMMON)/my_str_to_wordtab.c	\
		  $(DIR_COMMON)/read512_socket.c	\
		  $(DIR_COMMON)/count_tab.c		\
		  $(DIR_COMMON)/write512_socket.c

OBJ_SERVER	= $(SRC_SERVER:.c=.o)

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

OBJ_COMMON	= $(SRC_COMMON:.c=.o)

INCLUDES	= ./includes

CC		= gcc

RM		= rm -f

override CFLAGS	+= -Wall -Wextra -I $(INCLUDES) -ggdb -D DEBUG

all:		$(server) $(client)

$(server):	$(OBJ_SERVER) $(OBJ_COMMON)
		$(CC) $(CFLAGS) -o $(server) $(OBJ_SERVER) $(OBJ_COMMON)

$(client):	$(OBJ_CLIENT) $(OBJ_COMMON)
		$(CC) $(CFLAGS) -o $(client) $(OBJ_CLIENT) $(OBJ_COMMON)

clean:
		$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_COMMON)

fclean:		clean
		$(RM) $(server) $(client)

re:		fclean all

.PHONY:		all clean fclean re
