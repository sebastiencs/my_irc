/*
** write_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:27:44 2015 chapui_s
** Last update Fri Apr 10 17:30:09 2015 chapui_s
*/

#include "client.h"

int		write_server(t_client *client)
{
  write512_socket(client->fd, client->buffer_out, strlen(client->buffer_out));
  memset(client->buffer_out, 0, BUFFER_SIZE);
  client->action = READ;
  return (0);
}
