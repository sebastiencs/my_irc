/*
** loop_client.c for client in /home/cholet_v/rendu/my_irc
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 14:11:54 2015 cholet_v
** Last update Fri Apr 10 14:12:19 2015 cholet_v
*/

#include "client.h"

int		looking_for_server(t_client *client)
{
  char		buffer[1024];

  memset(buffer, 0, sizeof(buffer));
  if (read(0, buffer, 1023) < 1)
    {
      client->run = 0;
      return (0);
    }
  client->tab = my_str_to_wordtab(buffer);
  if (strcmp(client->tab[0], "/server") != 0)
    {
      free_wordtab(&(client->tab));
      return (0);
    }
  else
    try_connection(client);
  free_wordtab(&(client->tab));
  return (0);
}

int		loop_client(t_client *client)
{
  while (client->run == 1)
    {
      if (client->connect == 0)
	looking_for_server(client);
    }
  return (0);
}
