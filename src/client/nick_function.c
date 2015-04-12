/*
** nick_function.c for client in /home/cholet_v/rendu/my_irc/src/client
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 01:21:33 2015 cholet_v
** Last update Sun Apr 12 18:24:31 2015 cholet_v
*/

#include "client.h"

int	send_nick(t_client *client)
{
  if (count_tab(client->tab) != 2)
    return (derrorn("/nick only take 1 argument"));
  snprintf(client->buffer_out, 512, "NICK %s\r\nUSER %s %s 0 :%s",
	   client->tab[1], client->tab[1], client->tab[1], client->tab[1]);
  client->action = WRITE;
  client->nick = 1;
  return (0);
}
