/*
** send_file.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 08:26:03 2015 chapui_s
** Last update Sun Apr 12 10:06:11 2015 chapui_s
*/

#include "server.h"

int		send_file(t_server *server, t_client *client)
{
  t_client	*dest;
  int		size;

  if (count_tab(client->tab_cmd) >= 3)
  {
    dest = find_dest(server->root_clients, client->tab_cmd[1]);
    if (dest)
    {
      memset(dest->buffer_out, 0, BUFFER_SIZE);
      sprintf(dest->buffer_out, "SEND %-5s ", client->tab_cmd[2]);
      size = atoi(client->tab_cmd[2]);
      if (size > 0 && size < 450)
      {
	memcpy(dest->buffer_out + 11, client->buffer_in + 32, size);
	dest->action = WRITE;
	server->transfer = 1;
      }
    }
  }
  return (0);
}
