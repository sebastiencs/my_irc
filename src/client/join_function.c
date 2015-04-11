/*
** join_function.c for client in /home/cholet_v/rendu/my_irc/src/client
1;3802;0c**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:23:37 2015 cholet_v
** Last update Sun Apr 12 00:56:06 2015 cholet_v
*/

#include "client.h"

int		send_join(t_client *client)
{
  size_t	size;
  int		i;

  i = 0;
  if (count_tab(client->tab) != 2)
    return (derrorn("/join only take 1 argument"));
  snprintf(client->buffer_out, 512, "JOIN %s", client->tab[1]);
  client->action = WRITE;
  while (client->channel[i] != NULL && i <= 9)
    ++i;
  size = strlen(client->tab[1]);
  if (!(client->channel[i] = malloc(size + 1)))
    return (derror("malloc:"));
  memset(client->channel[i], 0, size + 1);
  strcpy(client->channel[i], client->tab[1]);
  client->current_chan = i;
  return (0);
}
