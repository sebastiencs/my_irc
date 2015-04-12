/*
** read512_socket.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 18:18:50 2015 chapui_s
** Last update Sun Apr 12 03:31:55 2015 cholet_v
*/

#include "common.h"

static int		is_end_of_line(char *s)
{
  size_t		i;

  i = 0;
  while (s[i])
    {
      if (s[i] == '\r' && s[i + 1] == '\n')
	return (1);
      i += 1;
    }
  return (0);
}

int			read512_socket(int fd, char *buffer)
{
  ssize_t		current;
  size_t		total;
  char			*begin;

  total = 0;
  memset(buffer, 0, BUFFER_SIZE);
  begin = buffer;
  while (total < BUFFER_SIZE - 1
	 && (current = read(fd, buffer, 1)) > 0
	 && !is_end_of_line(begin))
    {
      buffer += (size_t)current;
      total += current;
    }
  if (current == -1)
    {
      derror("read:");
    }
  return ((current == -1) ? (-1) : ((int)total));
}
