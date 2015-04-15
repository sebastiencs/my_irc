/*
** clear_line.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 05:20:25 2015 chapui_s
** Last update Wed Apr 15 23:46:54 2015 chapui_s
*/

#include "client.h"

static const char	g_dl[] = { 27, 91, 77, 0 };
static const char	g_cr[] = { 13, 0 };

void			clear_line()
{
  write(1, g_dl, strlen(g_dl));
  write(1, g_cr, strlen(g_cr));
}

void			clean_telnet(char *s)
{
  size_t		len;

  len = strlen(s);
  if (len > 1 && s[len - 1] == '\n' && s[len - 2] == '\r')
    {
      s[len - 1] = 0;
      s[len - 2] = 0;
      if (len > 2 && s[len - 3] == ' ')
	{
	  s[len - 3] = 0;
	}
    }
}

void			clear_and_print(char *s)
{
  clear_line();
  clean_telnet(s);
  fprintf(stdout, "%s\n", s);
}

void			clear_and_printf(char *fmt, ...)
{
  va_list		ap;

  clear_line();
  va_start(ap, fmt);
  vfprintf(stdout, fmt, ap);
  va_end(ap);
}
