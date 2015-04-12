/*
** clean_telnet.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 03:09:28 2015 chapui_s
** Last update Sun Apr 12 03:25:35 2015 cholet_v
*/

#include "server.h"

void		clean_telnet(char *s)
{
  size_t	len;

  len = strlen(s);
  if (len > 1)
    {
      if (s[len - 1] == '\n' && s[len - 2] == '\r')
	{
	  s[len - 1] = 0;
	  s[len - 2] = 0;
	}
    }
}
