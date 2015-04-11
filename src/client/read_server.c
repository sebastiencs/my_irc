/*
** read_server.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 17:25:07 2015 chapui_s
** Last update Sun Apr 12 00:57:09 2015 chapui_s
*/

#include "client.h"

static void	clean_telnet(char *s)
{
  size_t	len;

  len = strlen(s);
  if (len > 1 && s[len - 1] == '\n' && s[len - 2] == '\r')
  {
    s[len - 1] = 0;
    s[len - 2] = 0;
  }
}

void			clear_line()
{
  static const char	dl[] = {27, 91, 77, 0};
  static const char	cr[] = {13, 0};

  write(1, dl, strlen(dl));
  write(1, cr, strlen(cr));
}

static void	manage_prefix(t_client *client __attribute__ ((unused)),
			      char *buffer)
{
  char		**tab;
  char		*user;
  char		*dest;
  char		*msg;

  if (!(tab = my_str_to_wordtab(buffer)) || count_tab(tab) < 4)
    return ;
  user = ((char*)tab[0]) + 1;
  dest = tab[2];
  msg = strchr(buffer + 1, ':');
  if (msg)
  {
    msg += 1;
    clean_telnet(msg);
    clear_line();
    printf("%s <%s>: %s\n", dest, user, msg);
  }
}

static void	manage_code(t_client *client __attribute__ ((unused)),
			    char *buffer,
			    int code)
{
  char		*msg;

  msg = strchr(buffer, ':');
  if (msg)
  {
    msg += 1;
    clean_telnet(msg);
    clear_line();
    if (code == RPL_NAMREPLY)
    {
      printf("USERS: %s\n", msg);
    }
    else if (code != RPL_TOPIC && code != RPL_ENDOFNAMES)
    {
      printf("%s\n", msg);
    }
  }
}

int		read_server(t_client *client)
{
  char		buffer[BUFFER_SIZE];
  int		number;

  memset(buffer, 0, BUFFER_SIZE);
  read512_socket(client->fd, buffer);
  if (strlen(buffer) > 0 && buffer[0] == ':')
  {
    manage_prefix(client, buffer);
  }
  else if ((number = atoi(buffer)))
  {
    manage_code(client, buffer, number);
  }
  else
  {
    //MANAGE JE SAIS PAS QUOI
  }
  return (0);
}
