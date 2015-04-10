/*
** read_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:25:07 2015 chapui_s
** Last update Sat Apr 11 00:03:18 2015 cholet_v
*/

#include "client.h"

int		read_server(t_client *client)
{
  char		buffer[BUFFER_SIZE];

  read512_socket(client->fd, buffer);
  printf("%s\n", buffer);
  //POUR TEST LES RETOURS

  // En general t'ecris ce que tu recois sur la sortie standard
  // faudra juste parser 2-3 trucs
  return (0);
}
