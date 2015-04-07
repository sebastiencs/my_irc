/*
** join_chan.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 16:18:21 2015 chapui_s
** Last update Tue Apr  7 16:51:42 2015 chapui_s
*/

#include "server.h"

int		join_chan(t_server *server __attribute__ ((unused)),
			  t_client *client)
{
  if (!client->tab_cmd[1])
  {
    reply(client, ERR_NEEDMOREPARAMS, client->tab_cmd[0]);
  }
  else if (client->chanel)
  {
    reply(client, ERR_TOOMANYCHANNELS, client->tab_cmd[1]);
  }
  else
  {
    client->chanel = strdup(client->tab_cmd[1]);
#ifdef DEBUG
    fprintf(stdout, "--%s JOIN %s\n", client->nick, client->chanel);
#endif
  }
  return (0);
}
