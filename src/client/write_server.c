/*
** write_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:27:44 2015 chapui_s
** Last update Sat Apr 11 00:02:35 2015 cholet_v
*/

#include "client.h"

int		write_server(t_client *client)
{
  write512_socket(client->fd, client->buffer_out, strlen(client->buffer_out));
  memset(client->buffer_out, 0, BUFFER_SIZE);
  client->action = READ;
  return (0);
}
