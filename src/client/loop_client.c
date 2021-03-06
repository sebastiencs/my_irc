/*
** loop_client.c for client in /home/cholet_v/rendu/my_irc
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 14:11:54 2015 cholet_v
** Last update Thu Apr 16 00:04:53 2015 Victor Cholet
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
      return (read_cmd(client));
    }
  else if (FD_ISSET(client->fd, rfds))
    {
      return (read_server(client));
    }
  else if (FD_ISSET(client->fd, wfds))
    {
      return (write_server(client));
    }
  return (0);
}

static void	prompt(t_client *client)
{
  char		*channel;

  channel = client->channel[client->current_chan];
  if (channel && client->quitting != 1)
    {
      my_putstr("#");
      my_putstr(channel);
    }
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
