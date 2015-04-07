/*
** loop_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 15:43:27 2015 chapui_s
** Last update Tue Apr  7 16:42:59 2015 chapui_s
*/

#include "server.h"

t_client		*find_client(t_client *root,
				     fd_set *rfds,
				     fd_set *wfds)
{
  t_client		*tmp;
  int			fd;

  tmp = root->next;
  while (tmp != root)
  {
    fd = tmp->fd;
    if (FD_ISSET(fd, wfds) || FD_ISSET(fd, rfds))
      return (tmp);
    tmp = tmp->next;
  }
  return ((t_client*)0);
}

int			read_client(t_server *server, t_client *client)
{
  if (!read512_socket(client->fd, client->buffer_in))
  {
#ifdef DEBUG
    fprintf(stdout, "--CLIENT DISCONNECT-- (fd: %d)\n", client->fd);
#endif
    pop_client(server->root_clients, client);
  }
  else
  {
#ifdef DEBUG
    puts_telnet(client->buffer_in);
#endif
    clean_telnet(client->buffer_in);
    if ((client->tab_cmd = my_str_to_wordtab(client->buffer_in)))
    {
      interpret_command(server, client);
      free_wordtab(&(client->tab_cmd));
    }
  }
  return (0);
}

int			write_client(t_server *server __attribute__ ((unused)),
				     t_client *client)
{
  get_buffer(&(client->list_buffer), client->buffer_out);
  write512_socket(client->fd, client->buffer_out, strlen(client->buffer_out));
  memset(client->buffer_out, 0, BUFFER_SIZE);
  if (!client->list_buffer)
  {
    client->action = READ;
  }
  return (0);
}

int			manage_client(t_server *server,
				      fd_set *rfds,
				      fd_set *wfds)
{
  t_client		*client;

  client = find_client(server->root_clients, rfds, wfds);
  if (client)
  {
    if (FD_ISSET(client->fd, rfds))
      read_client(server, client);
    else
      write_client(server, client);
  }
  return (0);
}

int			post_select(t_server *server,
				    fd_set *rfds,
				    fd_set *wfds)
{
  if (FD_ISSET(server->fd, rfds))
  {
    add_client(server);
  }
  else
  {
    manage_client(server, rfds, wfds);
  }
  return (0);
}

int			loop_server(t_server *server)
{
  fd_set		rfds;
  fd_set		wfds;
  fd_set		efds;
  int			fdmax;

  while (server->alive)
  {
    fdmax = init_select(server, &rfds, &wfds, &efds);
    if (server->alive)
    {
      if (select(fdmax + 1, &rfds, &wfds, &efds, (struct timeval*)0) == -1)
      {
	return (derror("select:"));
      }
    }
    if (server->alive)
    {
      post_select(server, &rfds, &wfds);
    }
  }
  return (0);
}
