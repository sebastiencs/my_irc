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

typedef struct	s_client
{
  char		*ip;
  int		port;
  int		fd;
  int		run;
  int		connect;
  char		**tab;
}		t_client;

typedef struct	s_cmd
{
  char		*name;
  int		(*fct)();
}		t_cmd;

int		loop_client(t_client *client);
int		looking_for_server(t_client *client);
int		check_command(char **tab);
int		loop_client(t_client *client);
int		looking_for_server(t_client *client);
int		try_connection(t_client *client);
int		switch_server(t_client *client, int tmpfd);

int	send_nick();
int	send_list();
int	send_join();
int	send_users();
int	send_part();
int	send_private();

#endif /* !CLIENT_H_ */
