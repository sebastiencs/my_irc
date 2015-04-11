/*
** user_function.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:25:17 2015 cholet_v
** Last update Sat Apr 11 22:25:32 2015 chapui_s
*/

#include "client.h"

int		send_users(t_client *client)
{
  char		*channel;

  if (!(channel = client->channel[client->current_chan]))
    return (derror("You're not in any channel"));
  snprintf(client->buffer_out, 512, "NAMES %s", channel);
  client->action = WRITE;
  printf("send_users\n");
  return (0);
}
