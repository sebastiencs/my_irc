/*
** interpret_command.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 21:45:01 2015 chapui_s
** Last update Tue Apr  7 03:04:46 2015 chapui_s
*/

#include "server.h"

t_cmd		cmds[] =
{
  { "NICK ", set_nickname, 0 },
  { (char*)0, (void*)0, 0 }
};

int		interpret_command(t_server *server, t_client *client)
{
  size_t	i;
  int		ret;

  i = 0;
  ret = 0;
  while (cmds[i].name && strncmp(client->buffer_in,
				 cmds[i].name,
				 strlen(cmds[i].name)))
  {
    i += 1;
  }
  if (cmds[i].name)
  {
    client->nb_wrong_cmd = 0;
    ret = cmds[i].fct(server, client);
  }
  else
  {
    if (++(client->nb_wrong_cmd) >= LIMIT_WRONG)
    {
      pop_client(server->root_clients, client);
    }
  }
  return (ret);
}
