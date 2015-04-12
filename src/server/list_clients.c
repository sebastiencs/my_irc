/*
** list_clients.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 05:51:17 2015 chapui_s
** Last update Sun Apr 12 03:29:34 2015 cholet_v
*/

#include "server.h"

static t_client		*create_client(int fd)
{
  t_client		*new;

  if ((new = (t_client*)malloc(sizeof(t_client))))
    {
      memset(new, 0, sizeof(t_client));
      new->fd = fd;
    }
  else
    {
#ifdef DEBUG
      fprintf(stdout, "%s\n", "##COULD NOT ALLOC NEW CLIENT");
#endif
      derror("malloc:");
    }
  return (new);
}

int			push_client(t_client *root, int fd)
{
  t_client		*new;

  if ((new = create_client(fd)))
    {
      new->prev = root->prev;
      new->next = root;
      root->prev->next = new;
      root->prev = new;
#ifdef DEBUG
      fprintf(stdout, "--NEW CLIENT PUSH-- (fd: %d)\n", fd);
#endif
    }
  return ((new) ? (0) : (-1));
}

int			init_root(t_client **root)
{
  t_client		*new;

  if ((new = create_client(0)))
    {
      new->next = new;
      new->prev = new;
      *root = new;
    }
  return ((new) ? (0) : (-1));
}

void			pop_client(t_client *root, t_client *client)
{
  t_client		*tmp;

  if (root && client)
    {
      tmp = root->next;
      while (tmp != root)
	{
	  if (tmp == client)
	    {
	      tmp->prev->next = tmp->next;
	      tmp->next->prev = tmp->prev;
#ifdef DEBUG
	      fprintf(stdout, "--CLIENT POP-- (fd: %d)\n", tmp->fd);
#endif
	      free_client(tmp);
	      return ;
	    }
	  tmp = tmp->next;
	}
#ifdef DEBUG
      fprintf(stdout, "##TRY TO POP CLIENT UNFOUND##\n");
#endif
    }
}

void			free_list(t_client *root)
{
  t_client		*tmp;
  t_client		*tmp2;

  if (root)
    {
      tmp = root->next;
      while (tmp != root)
	{
	  tmp2 = tmp->next;
	  free_client(tmp);
	  tmp = tmp2;
	}
      free(root);
    }
}
