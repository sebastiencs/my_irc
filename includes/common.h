/*
** common.h for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 04:35:07 2015 chapui_s
** Last update Sun Apr 12 00:53:55 2015 chapui_s
*/

#ifndef COMMON_H_
# define COMMON_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <stdarg.h>
# include <errno.h>

# define ERR_NONICKNAMEGIVEN	(431)
# define ERR_NICKNAMEINUSE	(433)
# define ERR_ERRONEUSNICKNAME	(432)
# define ERR_NICKCOLLISION	(436)
# define ERR_UNKNOWNCOMMAND	(421)
# define ERR_NEEDMOREPARAMS	(461)
# define ERR_ALREADYREGISTRED	(462)
# define ERR_NOTREGISTERED	(451)
# define RPL_LISTSTART		(321)
# define RPL_LIST		(322)
# define RPL_LISTEND		(323)
# define ERR_TOOMANYCHANNELS	(405)
# define ERR_NOTONCHANNEL	(442)
# define ERR_NORECIPIENT	(411)
# define ERR_NOSUCHNICK		(401)
# define ERR_NOORIGIN		(409)
# define ERR_CANNOTSENDTOCHAN	(404)
# define RPL_TOPIC		(332)
# define RPL_NAMREPLY		(353)
# define RPL_ENDOFNAMES		(366)

typedef enum		e_action
{
  READ = 0,
  WRITE = 1,
}			t_action;

# define BUFFER_SIZE	(512 + 1)

int		derror(const char *);
int		derrorn(const char *);
int		read512_socket(int fd, char *buffer);
int		write512_socket(int fd, char *buffer, size_t size);
void		puts_telnet(const char *s);
char		**my_str_to_wordtab(char *s);
void		free_wordtab(char ***wordtab);
int		count_tab(char **tab);

#endif /* !COMMON_H_ */
