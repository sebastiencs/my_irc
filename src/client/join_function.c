/*
** join_function.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:23:37 2015 cholet_v
** Last update Sat Apr 11 00:16:16 2015 cholet_v
*/

#include "client.h"

int	send_join(t_client *client)
{
  int	i;

  i = 0;
  if (count_tab(client->tab) != 2)
    return (derrorn("/join only take 1 argument"));
  if (count_tab(client->channel) == 10)
    return (derrorn("You have too many chan opened"));
  snprintf(client->buffer_out, 512, "JOIN %s", client->tab[1]);
  client->action = WRITE;
  while (client->channel[i] == NULL && i <= 9)
    ++i;
  if (!(client->channel[i] = malloc(strlen(client->tab[1]) * sizeof(char))))
    return (derror("malloc:"));
  strcpy(client->channel[i], client->tab[i]);
  printf("send_join\n");
  return (0);
}