/*
** set_nickname.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 01:02:11 2015 chapui_s
** Last update Tue Apr  7 17:23:03 2015 chapui_s
*/

#include "server.h"

int		is_already_used(t_client *root, char *nick)
{
  t_client	*tmp;

  if (strlen(nick) > 9)
    nick[9] = 0;
  tmp = root->next;
  while (tmp != root)
  {
    if (tmp->nick && !strncmp(tmp->nick, nick, 9))
      return (1);
    tmp = tmp->next;
  }
  return (0);
}

int		is_bad_caracters(char *s)
{
  char		good[] = "-[]\\`^{}_";
  size_t	i;

  i = 0;
  while (s[i])
  {
    if (!(s[i] >= 'a' && s[i] <= 'z')
	&& !(s[i] >= 'A' && s[i] <= 'Z')
	&& !strchr(good, s[i]))
      return (1);
    i += 1;
  }
  return (0);
}

int		set_nickname(t_server *server, t_client *client)
{
  char		*nick;
  int		already_used;

  nick = client->tab_cmd[1];
  if (!nick)
  {
    reply(client, ERR_NONICKNAMEGIVEN);
    return (0);
  }
  already_used = is_already_used(server->root_clients, nick);
  if (client->nick && already_used)
    reply(client, ERR_NICKNAMEINUSE, nick);
  else if (is_bad_caracters(nick))
    reply(client, ERR_ERRONEUSNICKNAME, nick);
  else if (!client->nick && already_used)
    reply(client, ERR_NICKCOLLISION, nick);
  else
  {
    client->nick = strdup(nick);
#ifdef DEBUG
    fprintf(stdout, "--SET NICK-- (fd: %d) (nick: %s)\n", client->fd, nick);
#endif
  }
  return (0);
}
