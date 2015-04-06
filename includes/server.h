/*
** server.h for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 04:36:38 2015 chapui_s
** Last update Mon Apr  6 17:30:53 2015 chapui_s
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "common.h"

# define DEFAULT_PORT	(6667)
# define CLIENTS_MAX	(1024)
# define BUFFER_SIZE	(1024)
# define ADDR_LOCAL_IP	("8.8.8.8")
# define PORT_LOCAL_IP	(53)

typedef enum		e_action
{
  READ = 0,
  WRITE = 1,
}			t_action;

typedef char		t_buffer;

typedef struct		s_client
{
  int			fd;
  char			*nick;
  char			*user;
  char			*chanel;
  t_action		action;
  t_buffer		buffer_out[BUFFER_SIZE];
  t_buffer		buffer_in[BUFFER_SIZE];
  struct s_client	*prev;
  struct s_client	*next;
}			t_client;

typedef struct		s_server
{
  int			port;
  int			fd;
  int			alive;
  char			*local_ip;
  t_client		*root_clients;
}			t_server;

int		get_port(t_server *server, int argc, char **argv);
int		create_server(t_server *server);
int		push_client(t_client *root, int fd);
int		init_root(t_client **root);
void		pop_client(t_client *root, t_client *client);
void		free_list(t_client *root);
int		loop_server(t_server *server);
int		init_select(t_server *server, fd_set *rfds,
			    fd_set *wfds, fd_set *efds);
void		add_client(t_server *server);

#endif /* !SERVER_H_ */
