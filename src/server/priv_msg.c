/*
** priv_msg.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 17:56:14 2015 chapui_s
** Last update Fri Apr 10 00:23:51 2015 chapui_s
*/

#include "server.h"

static int	send_to_chanel(t_client *root, char *channel,
			       char *from, char *msg)
{
  t_client	*client;
  int		found;
  int		move;

  move = 0;
  client = root->next;
  if (channel[0] == '#' && ++move)
  {
    channel += 1;
  }
  msg += 1;
  found = -1;
  while (client != root)
  {
    if (client->channel && is_in_channel(client->channel, channel))
    {
      if (client->nick && strcmp(client->nick, from))
      {
	reply(client, 700, from, (move) ? (channel - 1) : (channel), msg);
      }
      found = 0;
    }
    client = client->next;
  }
  return (found);
}

static int	send_to_user(t_client *root, char *user,
			     char *from, char *msg)
{
  t_client	*client;

  client = root->next;
  msg += 1;
  while (client != root)
  {
    if (client->nick && !strcmp(client->nick, user))
    {
      reply(client, 700, from, user, msg);
      return (0);
    }
    client = client->next;
  }
  return (-1);
}

static int	try_channel(t_server *server, t_client *client, char *msg)
{
  int		ret;

  if (is_in_channel(client->channel, client->tab_cmd[1]))
  {
    ret = send_to_chanel(server->root_clients, client->tab_cmd[1],
			 client->nick, msg);
  }
  else
  {
    ret = 0;
    reply(client, ERR_CANNOTSENDTOCHAN, client->tab_cmd[1]);
  }
  return (ret);
}

int		priv_msg(t_server *server, t_client *client)
{
  char		*msg;
  int		ret;

  if (!client->tab_cmd[1] || client->tab_cmd[1][0] == ':')
    reply(client, ERR_NORECIPIENT, client->tab_cmd[0]);
  else if (client->tab_cmd[2])
  {
    msg = strchr(client->buffer_in, ':');
    if (client->tab_cmd[1][0] == '#')
    {
      ret = try_channel(server, client, msg);
    }
    else
    {
      ret = send_to_user(server->root_clients, client->tab_cmd[1],
			 client->nick, msg);
    }
    if (ret)
    {
      reply(client, ERR_NOSUCHNICK, client->tab_cmd[1]);
    }
  }
  return (0);
}
