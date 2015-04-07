/*
** reply.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Tue Apr  7 01:41:12 2015 chapui_s
** Last update Tue Apr  7 03:19:26 2015 chapui_s
*/

#include "server.h"

t_reply		tab_reply[] =
{
  { 401, "401 %s :No such nick/channel\r\n" },
  { 402, "402 %s :No such server\r\n" },
  { 403, "403 %s :No such channel\r\n" },
  { 404, "404 %s :Cannot send to channel\r\n" },
  { 405, "405 %s :You have joined too many channels\r\n" },
  { 406, "406 %s :There was no such nickname\r\n" },
  { 407, "407 %s :Duplicate recipients. No message delivered\r\n" },
  { 409, "409 :No origin specified\r\n" },
  { 411, "411 :No recipient given (%s)\r\n" },
  { 412, "412 :No text to send\r\n" },
  { 413, "413 %s :No toplevel domain specified\r\n" },
  { 414, "414 %s :Wildcard in toplevel domain\r\n" },
  { 421, "421 %s :Unknown command\r\n" },
  { 422, "422 :MOTD File is missing\r\n" },
  { 423, "423 %s :No administrative info available\r\n" },
  { 424, "424 :File error doing %s on %s\r\n" },
  { 431, "431 :No nickname given\r\n" },
  { 432, "432 %s :Erroneus nickname\r\n" },
  { 433, "433 %s :Nickname is already in use\r\n" },
  { 436, "436 %s :Nickname collision KILL\r\n" },
  { 441, "441 %s %s :They aren't on that channel\r\n" },
  { 442, "442 %s :You're not on that channel\r\n" },
  { 443, "443 %s %s :is already on channel\r\n" },
  { 444, "444 %s :User not logged in\r\n" },
  { 445, "445 :SUMMON has been disabled\r\n" },
  { 446, "446 :USERS has been disabled\r\n" },
  { 451, "451 :You have not registered\r\n" },
  { 461, "461 %s :Not enough parameters\r\n" },
  { 462, "462 :You may not reregister\r\n" },
  { 463, "463 :Your host isn't among the privileged\r\n" },
  { 464, "464 :Password incorrect\r\n" },
  { 465, "465 :You are banned from this server\r\n" },
  { 467, "467 %s :Channel key already set\r\n" },
  { 471, "471 %s :Cannot join channel (+l)\r\n" },
  { 472, "472 %s :is unknown mode char to me\r\n" },
  { 473, "473 %s :Cannot join channel (+i)\r\n" },
  { 474, "474 %s :Cannot join channel (+b)\r\n" },
  { 475, "475 %s :Cannot join channel (+k)\r\n" },
  { 481, "481 :Permission Denied- You're not an IRC operator\r\n" },
  { 482, "482 :You're not channel operator\r\n" },
  { 483, "483 :You cant kill a server!\r\n" },
  { 491, "491 :No O-lines for your host\r\n" },
  { 501, "501 :Unknown MODE flag\r\n" },
  { 502, "502 :Cant change mode for other users\r\n" },
  { 0, (char*)0 }
};

int		reply(t_client *client, int num, ...)
{
  va_list	ap;
  size_t	i;
  char		*buffer;

  i = 0;
  while (tab_reply[i].num && tab_reply[i].num != num)
  {
    i += 1;
  }
  if (tab_reply[i].num)
  {
    buffer = client->buffer_out;
    memset(buffer, 0, BUFFER_SIZE);
    va_start(ap, num);
    vsnprintf(buffer, 512, tab_reply[i].fmt, ap);
    va_end(ap);
    write512_socket(client->fd, buffer, strlen(buffer));
  }
#ifdef DEBUG
  else
  {
    fprintf(stdout, "##UNKNOWN REPLY CODE## (%d)\n", num);
  }
#endif
  return (0);
}