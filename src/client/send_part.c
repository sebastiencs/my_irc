/*
** send_part.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:24:29 2015 cholet_v
** Last update Sat Apr 11 00:28:38 2015 cholet_v
*/

#include "client.h"

int	send_part(t_client *client)
{
  int	i;

  i = 0;
  if (count_tab(client->tab) != 2)
    return (derrorn("/part only take 1 argument"));
  while (i < 10 && (strcmp(client->tab[1], client->channel[i]) != 0))
    ++i;
  if (i == 10)
    return (derrorn("Error you are not is this channel"));
  free(client->channel[i]);
  client->channel[i] = NULL;
  snprintf(client->buffer_out, 512, "PART %s", client->tab[1]);
  client->action = WRITE;
  printf("send_part\n");
  return (0);
}
