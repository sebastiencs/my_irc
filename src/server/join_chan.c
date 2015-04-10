/*
** join_chan.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 16:18:21 2015 chapui_s
** Last update Fri Apr 10 02:13:30 2015 chapui_s
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
      reply(tmp, 702, from, channel);
    }
    tmp = tmp->next;
  }
}

static void	send_info(t_server *server, t_client *client, char *channel)
{
  reply(client, RPL_TOPIC, client->nick, channel, TOPIC);
  names(server, client);
}

int		join_chan(t_server *server,
			  t_client *client)
{
  char		*channel;

  if (!client->tab_cmd[1])
  {
    reply(client, ERR_NEEDMOREPARAMS, client->tab_cmd[0]);
  }
  else
  {
    channel = client->tab_cmd[1];
    if (channel && channel[0] == '#')
    {
      channel += 1;
    }
    if (!is_in_channel(client->channel, channel))
    {
      push_channel(&(client->channel), channel);
      send_to_chanel(server->root_clients, client->nick, channel);
      send_info(server, client, channel);
#ifdef DEBUG
      fprintf(stdout, "--%s JOIN %s\n", client->nick, channel);
#endif
    }
  }
  return (0);
}
