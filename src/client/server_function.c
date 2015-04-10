/*
** server_function.c for client in /home/cholet_v/rendu/my_irc
**
** Made by cholet_v
** Login   <cholet_v@epitech.net>
**
** Started on  Fri Apr 10 14:10:42 2015 cholet_v
** Last update Fri Apr 10 14:11:49 2015 cholet_v
*/

#include "client.h"

int		switch_server(t_client *client, int tmpfd)
{
  close(client->fd);
  client->fd = tmpfd;
  return (0);
}

int		try_connection(t_client *client)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			tmpfd;

  if (!client->tab[1] || !client->tab[2])
    return (derrorn("Error /server arguments\nUsage: /server ip port\n"));
  client->ip = client->tab[1];
  client->port = atoi(client->tab[2]);
  if (!(pe = getprotobyname("TCP")))
    return (derrorn("getprotobyname failed\n"));
  if ((tmpfd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (derrorn("socket failed\n"));
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(client->port);
  s_in.sin_addr.s_addr = inet_addr(client->ip);
  if (connect(tmpfd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    return (derrorn("Connection failed\nServer non reachable\n"));
  if (client->connect == 1)
    switch_server(client, tmpfd);
  else
    {
      client->fd = tmpfd;
      client->connect = 1;
    }
  return (0);
}
