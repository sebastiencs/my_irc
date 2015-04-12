/*
** request.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 07:20:58 2015 chapui_s
** Last update Sun Apr 12 08:44:03 2015 chapui_s
*/

#include "server.h"

t_client	*find_dest(t_client *root, char *name)
{
  t_client	*tmp;

  tmp = root->next;
  while (tmp != root)
  {
    if (tmp->nick && !strcmp(tmp->nick, name))
    {
      return (tmp);
    }
    tmp = tmp->next;
  }
  return ((t_client*)0);
}

int		request(t_server *server, t_client *client)
{
  t_client	*dest;

  if (count_tab(client->tab_cmd) == 3)
  {
    if (!(dest = find_dest(server->root_clients, client->tab_cmd[1])))
    {
      reply(client, 704, "user not found");
    }
    else
    {
      reply(dest, 705, client->nick, client->tab_cmd[2]);
    }
  }
  return (0);
}

int		accept_file(t_server *server, t_client *client)
{
  t_client	*dest;

  if (count_tab(client->tab_cmd) == 2)
  {
    dest = find_dest(server->root_clients, client->tab_cmd[1]);
    if (dest)
    {
      reply(dest, 706, client->nick);
    }
  }
  return (0);
}
