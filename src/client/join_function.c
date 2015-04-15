/*
** join_function.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Apr 16 00:29:28 2015 chapui_s
** Last update Thu Apr 16 00:29:28 2015 chapui_s
*/

#include "client.h"

int		check_haveit(char *str, t_client *client)
{
  int		i;

  i = 0;
  while (i < (MAXCHAN - 1))
    {
      if (client->channel[i] && strcmp(str, client->channel[i]) == 0)
	return (1);
      ++i;
    }
  return (0);
}

int		send_join(t_client *client)
{
  size_t	size;
  int		i;

  i = 0;
  if (count_tab(client->channel) > MAXCHAN)
    return (derrorn("You have reach the limit of open chan"));
  if (count_tab(client->tab) != 2)
    return (derrorn("/join only take 1 argument"));
  if (check_haveit(client->tab[1], client) == 1)
    return (derrorn("You are already on this channel"));
  snprintf(client->buffer_out, 512, "JOIN %s", client->tab[1]);
  client->action = WRITE;
  while (client->channel[i] != NULL && i <= (MAXCHAN - 1))
    ++i;
  size = strlen(client->tab[1]);
  if (!(client->channel[i] = malloc(size + 1)))
    return (derror("malloc:"));
  memset(client->channel[i], 0, size + 1);
  strcpy(client->channel[i], client->tab[1]);
  client->current_chan = i;
  return (0);
}
