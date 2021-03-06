/*
** interpret_command.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 21:45:01 2015 chapui_s
** Last update Thu Apr 16 00:30:50 2015 chapui_s
*/

#include "server.h"

t_cmd		g_cmds[] =
{
  { "NICK", set_nickname, 0 },
  { "USER", set_user, 0 },
  { "LIST", list_chan, 1 },
  { "JOIN", join_chan, 1 },
  { "PART", part_chan, 1 },
  { "PRIVMSG", priv_msg, 1 },
  { "PING", ping_pong, 1 },
  { "NAMES", names, 1},
  { "REQUEST", request, 1},
  { "ACCEPT_FILE", accept_file, 1},
  { "SEND", send_file, 1 },
  { "QUIT", quit_client, 0 },
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
  while (g_cmds[i].name && strncmp(client->buffer_in,
				 g_cmds[i].name,
				 strlen(g_cmds[i].name)))
    i += 1;
  if (g_cmds[i].name && g_cmds[i].need_registered && !client->registered)
  {
    reply(client, ERR_NOTREGISTERED);
  }
  else if (g_cmds[i].name)
  {
    client->nb_wrong_cmd = 0;
    ret = g_cmds[i].fct(server, client);
  }
  else
  {
    manage_errors(server, client);
  }
  return (ret);
}
