/*
** find_client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 10:44:29 2015 chapui_s
** Last update Sun Apr 12 10:44:41 2015 chapui_s
*/

#include "server.h"

t_client		*find_client(t_client *root,
				     fd_set *rfds,
				     fd_set *wfds)
{
  t_client		*tmp;
  int			fd;

  tmp = root->next;
  while (tmp != root)
    {
      fd = tmp->fd;
      if (FD_ISSET(fd, wfds) || FD_ISSET(fd, rfds))
	return (tmp);
      tmp = tmp->next;
    }
  return ((t_client*)0);
}
