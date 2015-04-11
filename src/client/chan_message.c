/*
** chan_message.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Sat Apr 11 18:02:48 2015 cholet_v
** Last update Sat Apr 11 18:52:45 2015 cholet_v
*/

#include "client.h"

int	channel_message(t_client *client)
{
  if (client->channel[client->current_chan] == NULL)
    return (derrorn("You are not in a channel"));
  snprintf(client->buffer_out, 512, "PRIVMSG %s :%s",
	   client->channel[client->current_chan], client->buffer_in);
  client->action = WRITE;
  return (0);
}
