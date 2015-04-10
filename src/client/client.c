/*
** client.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 02:27:01 2015 chapui_s
** Last update Fri Apr 10 14:12:54 2015 cholet_v
*/

#include "client.h"

t_cmd		cmds[] =
  {
    { "/nick", send_nick },
    { "/list", send_list },
    { "/join", send_join },
    { "/part", send_part },
    { "/users", send_users },
    { "/msg", send_private },
    { "/server", try_connection},
    { (char*)0, (void*)0 }
  };

int		check_command(char **tab)
{
  int		i;

  i = 0;
  while (cmds[i].name &&
	 (strncmp(tab[0], cmds[i].name, strlen(cmds[i].name)) != 0))
    {
      ++i;
    }
  if (cmds[i].name)
    {
      printf("Command found\n");
      cmds[i].fct();
    }
  else
    printf("Command not found\n");
  return (0);
}

int		main(void)
{
  t_client	client;

  memset(&client, 0, sizeof(client));
  client.run = 1;
  client.connect = 0;
  loop_client(&client);
  return (0);
}
