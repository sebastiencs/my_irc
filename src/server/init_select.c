/*
** init_select.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 16:33:38 2015 chapui_s
** Last update Wed Apr  8 21:51:21 2015 chapui_s
*/

#include "server.h"

static int		init_writefds(t_client *root, fd_set *wfds, int *fdmax)
{
  t_client		*tmp;
  int			is_write;
  int			fd_current;

  tmp = root->next;
  is_write = 0;
  while (tmp != root)
  {
    if (tmp->action == WRITE)
    {
      fd_current = tmp->fd;
      FD_SET(fd_current, wfds);
      if (fd_current > *fdmax)
      {
	*fdmax = fd_current;
      }
      is_write = 1;
    }
    tmp = tmp->next;
  }
  return (is_write);
}

static void		init_readfds(t_client *root, fd_set *rfds, int *fdmax)
{
  t_client		*tmp;
  int			fd_current;

  tmp = root->next;
  while (tmp != root)
  {
    if (tmp->action == READ)
    {
      fd_current = tmp->fd;
      FD_SET(fd_current, rfds);
      if (fd_current > *fdmax)
      {
	*fdmax = fd_current;
      }
    }
    tmp = tmp->next;
  }
}

int			init_select(t_server *server, fd_set *rfds,
				    fd_set *wfds, fd_set *efds)
{
  int			fdmax;

  FD_ZERO(rfds);
  FD_ZERO(wfds);
  FD_ZERO(efds);
  FD_SET(server->fd, rfds);
  fdmax = server->fd;
  if (!init_writefds(server->root_clients, wfds, &fdmax))
  {
    init_readfds(server->root_clients, rfds, &fdmax);
  }
  return (fdmax);
}
