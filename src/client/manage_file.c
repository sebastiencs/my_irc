/*
** manage_file.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 10:30:47 2015 chapui_s
** Last update Thu Apr 16 00:10:39 2015 Victor Cholet
*/

#include "client.h"

void			clear_transfer(t_client *client)
{
   munmap(client->file_to_send, client->total);
   client->file_to_send = (void*)0;
   free(client->dest);
   client->dest = (char*)0;
   client->current = 0;
   client->total = 0;
 }

void			put_file_in_buffer(t_client *client)
{
  void			*data;
  size_t		tmp;
  int			sts;

  if (client->current >= client->total)
    {
      clear_and_print("transfer completed");
      client->action = READ;
      clear_transfer(client);
    }
  else
    {
      data = client->file_to_send;
      data += (size_t)client->current;
      memset(client->buffer_out, 0, BUFFER_SIZE);
      sts = 400;
      if ((int)client->total - (int)client->current < 400)
	sts = (int)client->total - (int)client->current;
      snprintf(client->buffer_out, 512, "SEND %-20s %-5d ", client->dest, sts);
      tmp = strlen(client->buffer_out);
      memcpy(client->buffer_out + tmp, data, sts);
      client->current += (size_t)sts;
      client->action = WRITE;
      client->transfer = 1;
    }
}

void			receive_file(t_client *client, char *buffer)
{
  void			*data;
  int			size;
  int			fd;

  clear_line();
  size = atoi(buffer + 5);
  data = buffer + 11;
  fd = open(FILE_RECEIVE, O_RDWR | O_APPEND | O_CREAT, 0644);
  if (fd != -1)
    {
      write(fd, data, size);
      close(fd);
    }
  snprintf(client->buffer_out, 512, "ACCEPT_FILE %s", client->sender);
  client->action = WRITE;
}
