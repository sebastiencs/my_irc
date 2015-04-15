/*
** quitting_chan.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Sun Apr 12 16:12:53 2015 cholet_v
** Last update Wed Apr 15 23:11:24 2015 chapui_s
*/

#include "client.h"

int		quit_loop(t_client *client)
{
  static int	pos;

  while (client->channel[pos] == NULL && pos < MAXCHAN)
    ++pos;
  if (pos == MAXCHAN)
    {
      client->quitting = 0;
      pos = 0;
      return (1);
    }
  snprintf(client->buffer_out, 512, "PART %s", client->channel[pos]);
  client->action = WRITE;
  free(client->channel[pos]);
  client->channel[pos] = NULL;
  ++pos;
  return (0);
}

int		quit(t_client *client)
{
  if (client->quitting == 0)
    client->quitting = 1;
  if (quit_loop(client) == 1)
    {
      client->nick = 0;
      client->connect = 0;
      close(client->fd);
      memset(&client->fd, 0, sizeof(client->fd));
    }
  return (0);
}
