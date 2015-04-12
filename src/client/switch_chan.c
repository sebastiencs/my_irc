/*
** switch_chan.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Sun Apr 12 02:20:02 2015 cholet_v
** Last update Sun Apr 12 05:05:19 2015 chapui_s
*/

#include "client.h"

static int	is_number(char *s)
{
  size_t	i;

  i = 0;
  while (s[i])
  {
    if (s[i] < '0' || s[i] > '9')
      return (0);
    i += 1;
  }
  return (1);
}

int	switch_chan(t_client *client)
{
  int	pos;

  if (count_tab(client->tab) != 2 || !is_number(client->tab[1]))
    return (derrorn("/switch usage: /switch _chan-number_"));
  pos = atoi(client->tab[1]);
  if (pos >= MAXCHAN || pos < 0)
    return (derrorn("chan number must be positive and less than the CHANMAX"));
  if (client->channel[pos] == NULL)
    return (derrorn("Error: empty slot"));
  client->current_chan = pos - 1;
  return (0);
}
