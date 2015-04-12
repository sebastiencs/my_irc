/*
** loop_client.c for client in /home/cholet_v/rendu/my_irc
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 14:11:54 2015 cholet_v
** Last update Sun Apr 12 02:49:26 2015 cholet_v
*/

#include "client.h"

static void	init_select(t_client *client,
			    fd_set *rfds,
			    fd_set *wfds,
			    fd_set *efds)
{
  FD_ZERO(rfds);
  FD_ZERO(wfds);
  FD_ZERO(efds);
  if (client->action == READ)
  {
    FD_SET(client->fd, rfds);
  }
  else
  {
    FD_SET(client->fd, wfds);
  }
  FD_SET(0, rfds);
}

static int	post_select(t_client *client,
			    fd_set *rfds,
			    fd_set *wfds)
{
  if (FD_ISSET(0, rfds))
  {
    // READ CMD
    return (read_cmd(client));
  }
  else if (FD_ISSET(client->fd, rfds))
  {
    // READ FROM SERVER
    return (read_server(client));
  }
  else if (FD_ISSET(client->fd, wfds))
  {
    return (write_server(client));
    // WRITE TO SERVER
  }
  return (0);
}

static void	prompt(t_client *client)
{
  if (client->channel[client->current_chan])
    write(1, client->channel[client->current_chan],
	  strlen(client->channel[client->current_chan]));
  write(1, "-> ", 3);
}

int		loop_client(t_client *client)
{
  fd_set	rfds;
  fd_set	wfds;
  fd_set	efds;
  int		fd_max;

  while (client->run == 1)
  {
    if (client->action == READ)
      prompt(client);
    init_select(client, &rfds, &wfds, &efds);
    if (client->run)
    {
      fd_max = client->fd + 1;
      if (select(fd_max, &rfds, &wfds, &efds, (struct timeval*)0) == -1)
      {
	return (derror("select:"));
      }
    }
    if (client->run)
    {
      if (post_select(client, &rfds, &wfds) < 0)
	return (0);
    }
  }
  return (0);
}
