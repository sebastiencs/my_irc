/*
** count_tab.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 04:40:07 2015 chapui_s
** Last update Sun Apr 12 03:30:59 2015 cholet_v
*/

#include "common.h"

int		count_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  i += 1;
	}
    }
  return (i);
}
