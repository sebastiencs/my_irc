/*
** client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 02:27:01 2015 chapui_s
** Last update Thu Apr 16 00:08:32 2015 Victor Cholet
*/

#include "client.h"

int		main(void)
{
  t_client     	client;

  signal(SIGPIPE, SIG_IGN);
  memset(&client, 0, sizeof(client));
  client.run = 1;
  client.connect = 0;
  client.quitting = 0;
  client.nick = 0;
  loop_client(&client);
  return (0);
}
