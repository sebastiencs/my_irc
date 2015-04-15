/*
** private_function.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:26:19 2015 cholet_v
** Last update Thu Apr 16 00:21:37 2015 chapui_s
*/

#include "client.h"

int	recup_msg(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != ' ' && str[i] != '\t')
    ++i;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  while (str[i] != ' ' && str[i] != '\t')
    ++i;
  while (str[i] == ' ' || str[i] == '\t')
    ++i;
  return (i);
}

int	send_private(t_client *client)
{
  int	pos;

  if (count_tab(client->tab) < 3)
    return (derrorn("/msg usage: /msg _nickname_ _message_"));
  pos = recup_msg(client->buffer_in);
  snprintf(client->buffer_out, 512, "PRIVMSG %s :%s",
	   client->tab[1], client->buffer_in + pos);
  client->action = WRITE;
  return (0);
}
