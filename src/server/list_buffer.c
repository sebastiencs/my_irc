/*
** list_buffer.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 16:26:51 2015 chapui_s
** Last update Tue Apr  7 16:35:29 2015 chapui_s
*/

#include "server.h"

static t_list_buffer	*create_buffer(char *buffer)
{
  t_list_buffer		*new;

  if ((new = (t_list_buffer*)malloc(sizeof(t_list_buffer))))
  {
    memset(new, 0, sizeof(t_list_buffer));
    memcpy(new, buffer, BUFFER_SIZE);
  }
  return (new);
}

void			push_buffer(t_list_buffer **list, t_buffer *buffer)
{
  t_list_buffer		*tmp;

  tmp = *list;
  if (tmp)
  {
    while (tmp->next)
    {
      tmp = tmp->next;
    }
    tmp->next = create_buffer(buffer);
  }
  else
  {
    *list = create_buffer(buffer);
  }
}

void			get_buffer(t_list_buffer **list, t_buffer *buffer_out)
{
  t_list_buffer		*tmp;

  memset(buffer_out, 0, BUFFER_SIZE);
  if (*list)
  {
    memcpy(buffer_out, (*list)->buffer, BUFFER_SIZE);
    tmp = (*list)->next;
    free(*list);
    *list = tmp;
  }
}
