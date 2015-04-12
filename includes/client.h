/*
** client.h for includes in /home/cholet_v/rendu/my_irc/includes
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Sun Apr 12 03:34:32 2015 cholet_v
** Last update Sun Apr 12 18:37:15 2015 cholet_v
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "common.h"

# define MAXCHAN	5
# define FILE_RECEIVE	("FILE_RECEIVE")

typedef struct		s_client
{
  char			*ip;
  int			port;
  int			fd;
  int			run;
  int			connect;
  char			**tab;
  t_action		action;
  char			buffer_out[BUFFER_SIZE];
  char			*buffer_in;
  char			*channel[MAXCHAN];
  int			current_chan;
  void			*file_to_send;
  char			*dest;
  size_t		current;
  size_t		total;
  char			*sender;
  int			transfer;
  int			quitting;
  int			nick;
}			t_client;

typedef struct		s_cmd
{
  char			*name;
  int			(*fct)(t_client *client);
  int			need_connected;
  int			need_nick;
}			t_cmd;

int			loop_client(t_client *client);
int			looking_for_server(t_client *client);
int			loop_client(t_client *client);
int			try_connection(t_client *client);
int			switch_server(t_client *client, int tmpfd);
int			read_cmd(t_client *client);
int			write_server(t_client *client);
int			read_server(t_client *client);
void			clear_line();
int			switch_chan(t_client *client);
int			send_nick(t_client *client);
int			send_list(t_client *client);
int			send_join(t_client *client);
int			send_users(t_client *client);
int			send_part(t_client *client);
int			send_private(t_client *client);
int			chanli(t_client *client);
int			channel_message(t_client *client);
void			clear_and_print(char *s);
void			clear_and_printf(char *fmt, ...);
void			clean_telnet(char *s);
int			send_file(t_client *client);
int			accept_file(t_client *client);
void			clear_transfer(t_client *client);
void			receive_file(t_client *client, char *buffer);
void			put_file_in_buffer(t_client *client);
int			quit(t_client *client);
int			quit_loop(t_client *client);

#endif /* !CLIENT_H_ */
