/*
** part_chan.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 17:07:22 2015 chapui_s
** Last update Sun Apr 12 03:29:53 2015 cholet_v
*/

#include "server.h"

static void	send_to_chanel(t_client *root, char *from, char *channel)
{
  t_client	*tmp;

  tmp = root->next;
  while (tmp != root)
    {
      if (tmp->channel && is_in_channel(tmp->channel, channel))
	{
	  reply(tmp, 703, from, channel);
	}
      tmp = tmp->next;
    }
}

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
      send_to_chanel(server->root_clients, client->nick, client->tab_cmd[1]);
      pop_channel(&(client->channel), get_channel_by_name(client->channel,
							  client->tab_cmd[1]));
    }
  return (0);
}
