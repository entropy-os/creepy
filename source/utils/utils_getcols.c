/*
** utils_getcols.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun May  1 01:56:59 2016 Benjamin Grange
** Last update Sun May  1 03:01:52 2016 Benjamin Grange
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

unsigned short		getcols(void)
{
  const	char		*env;
  int			c = (-1);

  if (!isatty(STDOUT_FILENO))
    c = 0;
  env = getenv("COLUMNS");
  if (env && *env)
    {
      char *p = NULL;
      c = strtol(env, &p, 10);
      if (*p != '\0')
	c = (-1);
    }
  if (c < 0)
    {
      #if defined(TIOCGSIZE)
	struct ttysize win;
	if (ioctl(STDOUT_FILENO, TIOCGSIZE, &win) == 0)
	  c = win.ts_cols;
      #elif defined(TIOCGWINSZ)
      	struct winsize win;
    	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &win) == 0)
	  c = win.ws_col;
      #endif
    }
  if (c < 0)
    c = 80;
  return (c);
}
