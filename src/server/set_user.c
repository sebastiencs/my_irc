/*
** set_user.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 04:39:01 2015 chapui_s
** Last update Tue Apr  7 05:00:58 2015 chapui_s
*/

#include "server.h"

int		set_user(t_server *server __attribute__ ((unused)),
			 t_client *client)
{
  char		*real_name;

  if (count_tab(client->tab_cmd) < 5)
  {
    reply(client, ERR_NEEDMOREPARAMS, client->tab_cmd[0]);
  }
  else if (client->registered)
  {
    reply(client, ERR_ALREADYREGISTRED);
  }
  else
  {
    client->user = client->tab_cmd[1];
    real_name = strrchr(client->buffer_in, ':');
    if (real_name)
    {
      client->real_name = strdup(real_name + 1);
    }
    client->registered = 1;
#ifdef DEBUG
    fprintf(stdout, "--SET USER--(fd %d user %s)\n", client->fd, client->user);
    fprintf(stdout, "--SET REAL NAME-- %s\n", client->real_name);
#endif
  }
  return (0);
}
