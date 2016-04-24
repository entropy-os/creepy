/*
** errors.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 18:06:26 2016 Benjamin Grange
** Last update Sun Apr 24 17:38:17 2016 Benjamin Grange
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "creepy.h"

void            print_error(const char *error_message, ...)
{
  va_list       va;

  va_start(va, error_message);
  vfprintf(stderr, error_message, va);
  va_end(va);
}
