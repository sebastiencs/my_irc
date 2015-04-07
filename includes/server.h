/*
** server.h for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 04:36:38 2015 chapui_s
** Last update Tue Apr  7 17:20:34 2015 chapui_s
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "common.h"

# define DEFAULT_PORT	(6667)
# define CLIENTS_MAX	(1024)
# define ADDR_LOCAL_IP	("8.8.8.8")
# define PORT_LOCAL_IP	(53)
# define LIMIT_WRONG	(10)

# define ERR_NONICKNAMEGIVEN	(431)
# define ERR_NICKNAMEINUSE	(433)
# define ERR_ERRONEUSNICKNAME	(432)
# define ERR_NICKCOLLISION	(436)
# define ERR_UNKNOWNCOMMAND	(421)
# define ERR_NEEDMOREPARAMS	(461)
# define ERR_ALREADYREGISTRED	(462)
# define ERR_NOTREGISTERED	(451)
# define RPL_LISTSTART		(321)
# define RPL_LIST		(322)
# define RPL_LISTEND		(323)
# define ERR_TOOMANYCHANNELS	(405)
# define ERR_NOTONCHANNEL	(442)

typedef enum		e_action
{
  READ = 0,
  WRITE = 1,
}			t_action;

typedef char		t_buffer;

typedef struct		s_list_buffer
{
  char			buffer[BUFFER_SIZE];
  struct s_list_buffer	*next;
}			t_list_buffer;

typedef struct		s_client
{
  int			fd;
  char			*nick;
  char			*user;
  char			*real_name;
  char			*chanel;
  int			registered;
  int			nb_wrong_cmd;
  t_action		action;
  char			**tab_cmd;
  t_buffer		buffer_out[BUFFER_SIZE];
  t_buffer		buffer_in[BUFFER_SIZE];
  t_list_buffer		*list_buffer;
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

typedef struct		s_cmd
{
  char			*name;
  int			(*fct)(t_server *server, t_client *client);
  int			need_registered;
}			t_cmd;

typedef struct		s_reply
{
  int			num;
  char			*fmt;
}			t_reply;

typedef struct		s_chan
{
  char			*name;
  int			nb_users;
  struct s_chan		*next;
}			t_chan;

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
int		interpret_command(t_server *server, t_client *client);
int		reply(t_client *client, int num, ...);
int		set_nickname(t_server *server, t_client *client);
void		clean_telnet(char *s);
void		free_client(t_client *client);
int		set_user(t_server *server, t_client *client);
int		list_chan(t_server *server, t_client *client);
int		join_chan(t_server *server, t_client *client);
int		part_chan(t_server *server, t_client *client);
void		push_buffer(t_list_buffer **list, t_buffer *buffer);
void		get_buffer(t_list_buffer **list, t_buffer *buffer_out);

#endif /* !SERVER_H_ */
