/*
** send_file.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 06:38:01 2015 chapui_s
** Last update Thu Apr 16 00:12:20 2015 Victor Cholet
*/

#include "client.h"

static size_t	get_size_file(char *file)
{
  struct stat	st;

  if (stat(file, &st) == -1)
    {
      return (derror("stat"));
    }
  return (st.st_size);
}

static void	*load_file(char *file, size_t *size)
{
  int		fd;
  void		*data;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      return ((void*)(long)derror("open:"));
    }
  if ((*size = get_size_file(file)) == (size_t)-1)
    {
      close(fd);
      return ((void*)-1);
    }
  data = mmap((void*)0, *size, PROT_READ, MAP_PRIVATE, fd, 0);
  close(fd);
  if (data == MAP_FAILED)
    {
      return ((void*)(long)derror("mmap:"));
    }
  return (data);
}

int		send_file(t_client *client)
{
  void		*data;
  size_t	size;

  if (count_tab(client->tab) == 3)
    {
      client->file_to_send = (void*)0;
      if (!(data = load_file(client->tab[2], &size)))
	{
	  return (0);
	}
      client->file_to_send = data;
      snprintf(client->buffer_out, 512, "REQUEST %s %s",
	       client->tab[1], client->tab[2]);
      client->dest = strdup(client->tab[1]);
      client->total = size;
      client->current = 0;
      client->action = WRITE;
    }
  return (0);
}
