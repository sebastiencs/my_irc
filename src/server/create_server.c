/*
** create_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 04:38:19 2015 chapui_s
** Last update Tue Apr  7 13:59:07 2015 chapui_s
*/

#include "server.h"

static int		get_local_ip(t_server *server)
{
  struct sockaddr_in	name;
  struct sockaddr_in	serv;
  socklen_t		size;
  char			buffer[BUFFER_SIZE];
  int			fd;

  size = sizeof(name);
  if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    return (-1);
  memset(&serv, 0, sizeof(serv));
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = inet_addr(ADDR_LOCAL_IP);
  serv.sin_port = htons(PORT_LOCAL_IP);
  if (connect(fd, (const struct sockaddr*)&serv, sizeof(serv)) == -1)
    return (-1);
  if (getsockname(fd, (struct sockaddr*)&name, &size) == -1)
    return (-1);
  server->local_ip = strdup(inet_ntop(AF_INET, &name.sin_addr,
				      buffer, BUFFER_SIZE));
  close(fd);
  return (0);
}

int			create_server(t_server *server)
{
  struct sockaddr_in	server_addr;
  int			unused;

  unused = 1;
  if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (derror("error: socket"));
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(server->port);
  if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR,
		 &unused, sizeof(int)) == -1)
    return (derror("error: setsockopt"));
  if ((bind(server->fd, (struct sockaddr*)&server_addr,
	    sizeof((server_addr)))) == -1)
    return (derror("error: bind"));
  if ((listen(server->fd, CLIENTS_MAX)) == -1)
    return (derror("error: listen"));
  get_local_ip(server);
  if (!server->local_ip)
    server->local_ip = strdup("127.0.0.1");
  printf("Server IP: %s\n", server->local_ip);
  printf("Server is listening on port %d\n", server->port);
  return (0);
}
