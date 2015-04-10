/*
** client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 02:27:01 2015 chapui_s
** Last update Fri Apr 10 16:54:51 2015 chapui_s
*/

#include "client.h"

int		main(void)
{
  t_client	client;

  memset(&client, 0, sizeof(client));
  client.run = 1;
  client.connect = 0;
  loop_client(&client);
  return (0);
}
