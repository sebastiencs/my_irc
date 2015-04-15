/*
** free_client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 03:46:17 2015 chapui_s
** Last update Thu Apr 16 00:03:52 2015 chapui_s
*/

#include "server.h"

void			free_channel(t_list_channel *list)
{
  t_list_channel	*tmp;

  while (list)
  {
    tmp = list->next;
    free(list->name);
    free(list);
    list = tmp;
  }
}

void			free_client(t_client *client)
{
  close(client->fd);
  free(client->nick);
  free(client->user);
  free(client->real_name);
  free_channel(client->channel);
  free(client);
}
