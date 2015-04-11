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

# define MAXCHAN	10

typedef struct	s_client
{
  char		*ip;
  int		port;
  int		fd;
  int		run;
  int		connect;
  char		**tab;
  t_action	action;
  char		buffer_out[BUFFER_SIZE];
  char		*buffer_in;
  char		*channel[MAXCHAN];
  int		current_chan;
}		t_client;

typedef struct	s_cmd
{
  char		*name;
  int		(*fct)(t_client *client);
  int		need_connected;
}		t_cmd;

int		loop_client(t_client *client);
int		looking_for_server(t_client *client);
int		loop_client(t_client *client);
int		try_connection(t_client *client);
int		switch_server(t_client *client, int tmpfd);
int		read_cmd(t_client *client);
int		write_server(t_client *client);
int		read_server(t_client *client);
void		clear_line();

int	send_nick(t_client *client);
int	send_list(t_client *client);
int	send_join(t_client *client);
int	send_users(t_client *client);
int	send_part(t_client *client);
int	send_private(t_client *client);
int	chanli(t_client *client);
int	channel_message(t_client *client);
#endif /* !CLIENT_H_ */
