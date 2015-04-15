/*
** ping_pong.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 19:33:36 2015 chapui_s
** Last update Thu Apr 16 00:09:41 2015 chapui_s
*/

#include "server.h"

int		ping_pong(t_server *server __attribute__ ((unused)),
			  t_client *client)
{
  char		*orig;

  orig = client->tab_cmd[1];
  if (orig)
  {
    reply(client, 701, orig, orig, orig);
  }
  else
  {
    reply(client, ERR_NOORIGIN);
  }
  return (0);
}
