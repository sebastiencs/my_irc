/*
** write_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:27:44 2015 chapui_s
** Last update Sun Apr 12 09:47:57 2015 chapui_s
*/

#include "client.h"

int		write_server(t_client *client)
{
  if (!client->transfer)
  {
    if (strlen(client->buffer_out) <= BUFFER_SIZE - 3)
    {
      strcat(client->buffer_out, "\r\n");
    }
#ifdef DEBUG
    else
    {
      fprintf(stdout, "%s\n", "##Too many character in write_server##");
    }
#endif
    write512_socket(client->fd, client->buffer_out, strlen(client->buffer_out));
  }
  else
  {
    write512_socket(client->fd, client->buffer_out, 512);
  }
  memset(client->buffer_out, 0, BUFFER_SIZE);
  client->action = READ;
  return (0);
}
