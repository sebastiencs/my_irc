/*
** write512_socket.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 18:18:11 2015 chapui_s
** Last update Thu Apr 16 00:15:14 2015 chapui_s
*/

#include "common.h"

int			write512_socket(int fd, char *buffer, size_t size)
{
  ssize_t		current;
  size_t		total;

  total = 0;
  if (size > 512)
  {
    size = 512;
#ifdef DEBUG
    fprintf(stdout, "%s\n", "##TRY TO WRITE MORE THAN 512 BYTES##");
#endif
  }
  while (total < size && (current = write(fd, buffer, size)) > 0)
  {
    buffer += (size_t)current;
    total += current;
  }
  if (current == -1)
  {
    derror("write:");
  }
  return ((current == -1) ? (-1) : (0));
}
