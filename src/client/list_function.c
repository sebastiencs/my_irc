/*
** list_function.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:22:42 2015 cholet_v
** Last update Fri Apr 10 23:59:03 2015 cholet_v
*/

#include "client.h"

int	send_list(t_client *client)
{
  if (count_tab(client->tab) > 2)
    return (derrorn("/list only take 0 or 1 argument"));
  if (client->tab[1])
    snprintf(client->buffer_out, 512, "LIST %s", client->tab[1]);
  else
    snprintf(client->buffer_out, 512, "LIST");
  client->action = WRITE;
  printf("send_list\n");
  return (0);
}
