/*
** read_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:25:07 2015 chapui_s
** Last update Thu Apr 16 00:06:10 2015 Victor Cholet
*/

#include "client.h"

static void	manage_prefix(t_client *client __attribute__ ((unused)),
			      char *buffer)
{
  char		**tab;
  char		*user;
  char		*dest;
  char		*msg;

  if (!(tab = my_str_to_wordtab(buffer)))
    return ;
  if (count_tab(tab) >= 4)
    {
      user = ((char*)tab[0]) + 1;
      dest = tab[2];
      msg = strchr(buffer + 1, ':');
      if (msg)
	{
	  clear_and_printf("%s <%s>: %s\n", dest, user, msg + 1);
	}
    }
  else
    {
      clear_and_print(buffer + 1);
    }
  free_wordtab(&tab);
}

static void		manage_code(t_client *client __attribute__ ((unused)),
				    char *buffer,
				    int code)
{
  char			*msg;

  msg = strchr(buffer, ':');
  if (msg)
    {
      msg += 1;
      if (code == RPL_NAMREPLY)
	{
	  clear_and_printf("Users in channel: [%s]\n", msg);
	}
      else if (code != RPL_TOPIC && code != RPL_ENDOFNAMES
	       && code != RPL_LISTSTART && code != RPL_LISTEND)
	{
	  clear_and_print(msg);
	}
      else
	{
	  clear_line();
	}
    }
  else
    {
      clear_and_print(buffer + 4);
    }
}

void			manage_other(t_client *client,
				     char *buffer)
{
  if (!strncmp(buffer, "SEND", strlen("SEND")))
    {
      receive_file(client, buffer);
    }
  else if (!strncmp(buffer, "RREQUEST", strlen("RREQUEST")))
    {
      if (strstr(buffer, "OK"))
	{
	  clear_line();
	  put_file_in_buffer(client);
	}
      else
	{
	  clear_transfer(client);
	}
    }
  else
    {
      clear_and_print(buffer);
    }
}

int			read_server(t_client *client)
{
  char			buffer[BUFFER_SIZE];
  int			number;

  memset(buffer, 0, BUFFER_SIZE);
  if (read512_socket(client->fd, buffer) <= 0)
    {
      clear_line();
      return (derrorn("Server disconnect"));
    }
  if (strlen(buffer) > 0 && buffer[0] == ':')
    {
      clean_telnet(buffer);
      manage_prefix(client, buffer);
    }
  else if ((number = atoi(buffer)))
    {
      clean_telnet(buffer);
      manage_code(client, buffer, number);
    }
  else
    {
      manage_other(client, buffer);
    }
  return (0);
}
