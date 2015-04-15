/*
** list_chan.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 15:19:21 2015 chapui_s
** Last update Thu Apr 16 00:06:13 2015 chapui_s
*/

#include "server.h"

static void	free_chan(t_chan *channels)
{
  t_chan	*tmp;

  while (channels)
  {
    tmp = channels->next;
    free(channels);
    channels = tmp;
  }
}

static t_chan	*create_chan(char *name)
{
  t_chan	*new;

  if ((new = (t_chan*)malloc(sizeof(t_chan))))
  {
    new->name = name;
    new->nb_users = 1;
    new->next = (t_chan*)0;
  }
  return (new);
}

static void	push_chan(t_chan **list, char *name)
{
  t_chan	*tmp;

  tmp = *list;
  if (tmp)
  {
    while (tmp->next)
    {
      if (!strcmp(tmp->name, name))
      {
	tmp->nb_users += 1;
	return ;
      }
      tmp = tmp->next;
    }
    if (tmp && !strcmp(tmp->name, name))
      tmp->nb_users += 1;
    else
      tmp->next = create_chan(name);
  }
  else
  {
    *list = create_chan(name);
  }
}

static t_chan		*get_list(t_client *root)
{
  t_list_channel	*list_channel;
  t_chan		*channels;
  t_client		*client;

  channels = (t_chan*)0;
  client = root->next;
  while (client != root)
  {
    list_channel = client->channel;
    while (list_channel)
    {
      push_chan(&channels, list_channel->name);
      list_channel = list_channel->next;
    }
    client = client->next;
  }
  return (channels);
}

int		list_chan(t_server *server, t_client *client)
{
  t_chan	*channels;
  t_chan	*save;

  channels = get_list(server->root_clients);
  save = channels;
  reply(client, RPL_LISTSTART);
  while (channels)
  {
    if ((client->tab_cmd[1] && strstr(channels->name, client->tab_cmd[1]))
	|| !client->tab_cmd[1])
    {
      reply(client, RPL_LIST, channels->name, channels->nb_users);
    }
    channels = channels->next;
  }
  reply(client, RPL_LISTEND);
  free_chan(save);
  return (0);
}
