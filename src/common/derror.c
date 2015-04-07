/*
** derror.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Mar 16 07:37:20 2015 chapui_s
** Last update Tue Apr  7 14:23:11 2015 chapui_s
*/

#include "common.h"

int			derrorn(const char *s)
{
  puts(s);
  return (-1);
}

int			derror(const char *s)
{
  if (errno != EINTR)
    perror(s);
  return ((errno != EINTR) ? (-1) : (0));
}
