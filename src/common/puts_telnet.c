/*
** puts_telnet.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 21:22:22 2015 chapui_s
** Last update Sun Apr 12 03:31:41 2015 cholet_v
*/

#include "common.h"

void		puts_telnet(const char *s)
{
  char		buffer[BUFFER_SIZE];
  size_t	len;

  len = strlen(s);
  if (len >= 2)
    {
      snprintf(buffer, len - 1, "%s", s);
      fprintf(stdout, "COMMAND: '%s'\n", buffer);
    }
}
