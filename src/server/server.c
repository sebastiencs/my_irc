/*
** server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 02:26:45 2015 chapui_s
** Last update Tue Apr  7 03:52:54 2015 chapui_s
*/

#include "server.h"

int			quit_server(t_server *server, int code_return)
{
  close(server->fd);
  free(server->local_ip);
  free_list(server->root_clients);
  return (code_return);
}

void			jump_quit(t_server *srv)
{
  static t_server	*server;

  if (srv)
  {
    server = srv;
  }
  else if (server)
  {
    quit_server(server, 0);
  }
}

void		catch_sigint(int sig)
{
  (void)sig;
  jump_quit((t_server*)0);
  exit(0);
}

int		main(int argc, char **argv)
{
  t_server	server;
  int		code_return;

  memset(&server, 0, sizeof(t_server));
  code_return = 0;
  server.alive = 1;
  signal(SIGPIPE, SIG_IGN);
  signal(SIGINT, catch_sigint);
  jump_quit(&server);
  if (get_port(&server, argc, argv) == -1
      || create_server(&server) == -1
      || init_root(&(server.root_clients)) == -1
      || loop_server(&server) == -1)
    code_return = -1;
  return (quit_server(&server, code_return));
}
