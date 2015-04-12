/*
** my_puts.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 06:20:19 2015 chapui_s
** Last update Sun Apr 12 06:22:49 2015 chapui_s
*/

#include "common.h"

size_t		my_putstr(const char *s)
{
  size_t	i;

  i = 0;
  if (s)
  {
    while (s[i])
    {
      write(1, s + i, 1);
      i += 1;
    }
  }
  return (i);
}
