/*
** list_channel.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Thu Apr  9 22:44:41 2015 chapui_s
** Last update Fri Apr 10 00:24:37 2015 chapui_s
*/

#include "server.h"

static t_list_channel	*create_channel(char *name)
{
  t_list_channel	*new;

  if ((new = (t_list_channel*)malloc(sizeof(t_list_channel))))
  {
    new->name = strdup(name);
    new->prev = (t_list_channel*)0;
    new->next = (t_list_channel*)0;
  }
#ifdef DEBUG
  else
  {
    fprintf(stdout, "##COULD NOT ALLOC CHANNEL## %s\n", name);
  }
#endif
  return (new);
}

int			push_channel(t_list_channel **list,
				     char *name)
{
  t_list_channel	*tmp;
  t_list_channel	*new;

  tmp = *list;
  new = create_channel(name);
  if (tmp)
  {
    while (tmp->next)
    {
      tmp = tmp->next;
    }
    tmp->next = new;
    new->prev = tmp;
  }
  else
  {
    *list = new;
  }
  return (0);
}

void			pop_channel(t_list_channel **list,
				    t_list_channel *to_pop)
{
  t_list_channel	*tmp;

  tmp = *list;
  while (tmp && to_pop)
  {
    if (tmp == to_pop)
    {
      if (tmp->prev)
      {
	tmp->prev->next = tmp->next;
      }
      if (tmp->next)
      {
	tmp->next->prev = tmp->prev;
      }
      free(tmp->name);
      free(tmp);
      if (tmp == *list)
      {
	*list = (t_list_channel*)0;
      }
      return ;
    }
    tmp = tmp->next;
  }
}

t_list_channel		*get_channel_by_name(t_list_channel *list,
					     char *name)
{
  while (list)
  {
    if (list->name && !strcmp(list->name, name))
      return (list);
    list = list->next;
  }
  return ((t_list_channel*)0);
}

int			is_in_channel(t_list_channel *list,
				      char *name)
{
  if (name && name[0] == '#')
  {
    name += 1;
  }
  while (list && name)
  {
    if (list->name && !strcmp(list->name, name))
      return (1);
    list = list->next;
  }
  return (0);
}
