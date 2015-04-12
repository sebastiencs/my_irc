/*
** accept_file.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 07:54:00 2015 chapui_s
** Last update Sun Apr 12 09:38:39 2015 chapui_s
*/

#include "client.h"

int		accept_file(t_client *client)
{
  if (client->tab[1])
  {
    client->sender = strdup(client->tab[1]);
    snprintf(client->buffer_out, 512, "ACCEPT_FILE %s", client->tab[1]);
    client->action = WRITE;
  }
  else
  {
    printf("usage accept_file: /accept_file __user__\n");
  }
  return (0);
}
