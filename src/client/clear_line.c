/*
** clear_line.c for epitech in /home/chapuis_s/rendu/
**
** Made by chapui_s
** Login   <chapui_s@epitech.eu>
**
** Started on  Sun Apr 12 05:20:25 2015 chapui_s
** Last update Sun Apr 12 06:15:46 2015 chapui_s
*/

#include "client.h"

void			clear_line()
{
  static const char	dl[] = { 27, 91, 77, 0 };
  static const char	cr[] = { 13, 0 };

  write(1, dl, strlen(dl));
  write(1, cr, strlen(cr));
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
