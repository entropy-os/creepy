/*
** utils_verbose.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 15:37:24 2016 Benjamin Grange
** Last update Sun Apr 24 15:50:52 2016 Benjamin Grange
*/

#include <stdarg.h>
#include "creepy.h"

void			verbose(t_creepy *creepy, const char *fmt, ...)
{
  va_list		va;

  va_start(va, fmt);
  if (creepy->params.verbose)
    {
      vprintf(fmt, va);
      printf("\n");
    }
  va_end(va);
}
