/*
** common.h for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Mon Apr  6 04:35:07 2015 chapui_s
** Last update Mon Apr  6 21:26:10 2015 chapui_s
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

# define BUFFER_SIZE	(512 + 1)

int		derror(const char *);
int		derrorn(const char *);
int		read512_socket(int fd, char *buffer);
int		write512_socket(int fd, char *buffer, size_t size);
void		puts_telnet(const char *s);

#endif /* !COMMON_H_ */
