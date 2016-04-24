/*
** errors.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 18:06:26 2016 Benjamin Grange
** Last update Sun Apr 24 02:14:55 2016 Benjamin Grange
*/

#include <stdarg.h>
#include <stdio.h>
#include "creepy.h"

void			print_error(const char *err, ...)
{
  va_list		va;

  va_start(va, err);
  vfprintf(stderr, err, va);
  va_end(va);
}

int			print_errori(const char *err, ...)
{
  va_list		va;

  va_start(va, err);
  vfprintf(stderr, err, va);
  va_end(va);
  return (1);
}

void			*print_errorn(const char *err, ...)
{
  va_list		va;

  va_start(va, err);
  vfprintf(stderr, err, va);
  va_end(va);
  return (NULL);
}
