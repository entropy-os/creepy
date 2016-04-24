/*
** utils_strdup.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 18:17:10 2016 Benjamin Grange
** Last update Sun Apr 24 18:25:13 2016 Benjamin Grange
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "creepy.h"

char			*creepy_asprintf(const char *fmt, ...)
{
  va_list		ap;
  va_list		copy;

  va_start(ap, fmt);
  va_copy(copy, ap);
  int length = vsnprintf(NULL, 0, fmt, copy);
  va_end(copy);
  if (length < 0)
    return (NULL);

  char *ptr = malloc((size_t)length + 1);
  if (!ptr)
    die("asprintf() failed (Not enough memory?)\n");
  int out = vsprintf(ptr, fmt, ap);
  if (out < 0)
    {
      free(ptr);
      return NULL;
    }
  va_end(ap);
  return ptr;
}

char			*creepy_strdup(const char *str)
{
  size_t		len;
  char			*s;

  len = strlen(str) + 1;
  if (!(s = malloc(sizeof(char) * len)))
    return (NULL);
  return (memcpy(s, str, len));
}
