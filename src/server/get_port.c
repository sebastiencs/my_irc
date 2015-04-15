/*
** get_port.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 04:15:57 2015 chapui_s
** Last update Thu Apr 16 00:04:03 2015 chapui_s
*/

#include "server.h"

int		get_port(t_server *server, int argc, char **argv)
{
  int		port;

  port =  DEFAULT_PORT;
  if (argc > 1)
  {
    port = atoi(argv[1]);
  }
  if (port <= 0 || port >= 0xFFFF)
  {
    fprintf(stderr, "%s: %s\n", argv[0], "Wrong port number");
    return (-1);
  }
  else
  {
    server->port = port;
    return (0);
  }
}
