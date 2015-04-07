/*
** interpret_command.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 21:45:01 2015 chapui_s
** Last update Tue Apr  7 15:39:31 2015 chapui_s
*/

#include "server.h"

t_cmd		cmds[] =
{
  { "NICK", set_nickname, 0 },
  { "USER", set_user, 0 },
  { "LIST", list_chan, 1 },
  { (char*)0, (void*)0, 0 }
};

static void	manage_errors(t_server *server, t_client *client)
{
  reply(client, ERR_UNKNOWNCOMMAND, client->tab_cmd[0]);
  if (++(client->nb_wrong_cmd) >= LIMIT_WRONG)
  {
    pop_client(server->root_clients, client);
  }
}

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
  if (cmds[i].name && cmds[i].need_registered && !client->registered)
  {
    reply(client, ERR_NOTREGISTERED);
  }
  else if (cmds[i].name)
  {
    client->nb_wrong_cmd = 0;
    ret = cmds[i].fct(server, client);
  }
  else
  {
    manage_errors(server, client);
  }
  return (ret);
}
