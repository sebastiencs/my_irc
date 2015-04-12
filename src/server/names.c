/*
** names.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Wed Apr  8 00:56:38 2015 chapui_s
** Last update Sun Apr 12 03:27:12 2015 cholet_v
*/

#include "server.h"

static void	add_name(char *buffer, char *name, size_t *i)
{
  strcat(buffer, name);
  strcat(buffer, " ");
  *i = *i + 1;
}

static void	send_buffer(t_client *client,
			    char *buffer,
			    char *chanel,
			    size_t *i)
{
  reply(client, RPL_NAMREPLY, client->nick, chanel, buffer);
  memset(buffer, 0, BUFFER_SIZE);
  *i = 0;
}

int		names(t_server *server, t_client *client)
{
  char		buffer[BUFFER_SIZE];
  t_client	*list;
  char		*chanel;
  size_t	i;

  i = 0;
  memset(buffer, 0, BUFFER_SIZE);
  chanel = client->tab_cmd[1];
  if (chanel && chanel[0] == '#')
    chanel += 1;
  list = server->root_clients->next;
  while (list != server->root_clients)
    {
      if (is_in_channel(list->channel, chanel))
	add_name(buffer, list->nick, &i);
      if (i == 20)
	send_buffer(client, buffer, chanel, &i);
      list = list->next;
    }
  if (i > 0)
    reply(client, RPL_NAMREPLY, client->nick, chanel, buffer);
  reply(client, RPL_ENDOFNAMES, client->nick, chanel);
  return (0);
}
