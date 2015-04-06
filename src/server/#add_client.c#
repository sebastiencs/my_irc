/*
** add_client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 16:58:26 2015 chapui_s
** Last update Mon Apr  6 16:58:33 2015 chapui_s
*/

#include "server.h"

void			add_client(t_server *server)
{
  struct sockaddr_in	a;
  size_t		size;
  int			fd;

  size = sizeof(a);
  if ((fd = accept(server->fd, (struct sockaddr*)&a, (socklen_t*)&size)) == -1)
  {
#ifdef DEBUG
    fprintf(stdout, "%s\n", "##COULD NOT ACCEPT CLIENT##");
#endif
    return ;
  }
  if (push_client(server->root_clients, fd) == -1)
  {
    close(fd);
  }
}
