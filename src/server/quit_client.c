/*
** quit_client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Wed Apr 15 23:22:27 2015 chapui_s
** Last update Wed Apr 15 23:43:29 2015 chapui_s
*/

#include "server.h"

int			quit_client(t_server *server, t_client *client)
{
  size_t		i;
  char			**tab;

  i = 0;
  tab = client->tab_cmd;
  while (tab && tab[i])
  {
    free(tab[i]);
    i += 1;
  }
  free(tab);
  client->tab_cmd = (char**)0;
  pop_client(server->root_clients, client);
  return (0);
}
