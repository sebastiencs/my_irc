/*
** free_client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 03:46:17 2015 chapui_s
** Last update Tue Apr  7 03:47:10 2015 chapui_s
*/

#include "server.h"

void		free_client(t_client *client)
{
  free(client->nick);
  free(client->user);
  free(client->chanel);
  free(client);
}
