/*
** read_cmd.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Fri Apr 10 16:51:56 2015 chapui_s
** Last update Sun Apr 12 00:58:47 2015 cholet_v
*/

#include "client.h"

t_cmd		cmds[] =
{
  { "/nick", send_nick, 1 },
  { "/list", send_list, 1 },
  { "/join", send_join, 1 },
  { "/part", send_part, 1 },
  { "/users", send_users, 1 },
  { "/msg", send_private, 1 },
  { "/server", try_connection, 0 },
  { "/chanli", chanli, 1},
  { (char*)0, (void*)0, 0 }
};

int		chanli(t_client *client)
{
  int		i;

  i = 0;
  printf("Current-- %d\nTotal-- %d\n",
	 client->current_chan, count_tab(client->channel));
  while (i < 10)
    {
      if (client->channel[i] != NULL)
	printf("%s\n", client->channel[i]);
      ++i;
    }
  return (0);
}

static int	check_command(t_client *client, char **tab)
{
  int		i;

  i = 0;
  while (cmds[i].name &&
	 (strncmp(tab[0], cmds[i].name, strlen(cmds[i].name)) != 0))
  {
    ++i;
  }
  if (cmds[i].name && cmds[i].need_connected == 1 && client->connect == 0)
    printf("You are not connected\n");
  else if (cmds[i].name)
    cmds[i].fct(client);
  else
    channel_message(client);
  return (0);
}

static void	clean_buffer(char *buffer)
{
  size_t	len;

  len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n')
  {
    buffer[len - 1] = 0;
  }
}

int		read_cmd(t_client *client)
{
  char		buffer[BUFFER_SIZE];

  memset(buffer, 0, BUFFER_SIZE);
  fgets(buffer, 512, stdin);
  clean_buffer(buffer);
  if (strlen(buffer) > 0 && (client->tab = my_str_to_wordtab(buffer)))
    {
      client->buffer_in = buffer;
      check_command(client, client->tab);
      free_wordtab(&(client->tab));
    }
  return (0);
}
