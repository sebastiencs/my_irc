/*
** read_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:25:07 2015 chapui_s
** Last update Fri Apr 10 17:28:44 2015 chapui_s
*/

#include "client.h"

int		read_server(t_client *client)
{
  char		buffer[BUFFER_SIZE];

  read512_socket(client->fd, buffer);
  // En general t'ecris ce que tu recois sur la sortie standard
  // faudra juste parser 2-3 trucs
  return (0);
}
