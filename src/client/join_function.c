/*
** join_function.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:23:37 2015 cholet_v
** Last update Fri Apr 10 20:19:52 2015 cholet_v
*/

#include "client.h"

int	send_join(t_client *client)
{
  if (count_tab(client->tab) != 2)
    return (derrorn("/join only take 1 argument"));
  snprintf(client->buffer_out, 512, "JOIN %s", client->tab[1]);
  client->action = WRITE;
  printf("send_join\n");
  return (0);
}
