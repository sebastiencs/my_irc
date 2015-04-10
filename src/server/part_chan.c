/*
** part_chan.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 17:07:22 2015 chapui_s
** Last update Fri Apr 10 00:24:58 2015 chapui_s
*/

#include "server.h"

int		part_chan(t_server *server __attribute__ ((unused)),
			  t_client *client)
{
  if (!client->tab_cmd[1])
  {
    reply(client, ERR_NEEDMOREPARAMS, client->tab_cmd[0]);
  }
  else if (!client->channel || !is_in_channel(client->channel,
					      client->tab_cmd[1]))
  {
    reply(client, ERR_NOTONCHANNEL, client->tab_cmd[1]);
  }
  else
  {
#ifdef DEBUG
    fprintf(stdout, "--%s PART %s--\n", client->nick, client->tab_cmd[1]);
#endif
    pop_channel(&(client->channel), get_channel_by_name(client->channel,
							client->tab_cmd[1]));
  }
  return (0);
}
