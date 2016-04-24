/*
** utils_die.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 17:38:20 2016 Benjamin Grange
** Last update Sun Apr 24 17:39:04 2016 Benjamin Grange
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void            die(const char *error_message, ...)
{
  va_list       va;

  va_start(va, error_message);
  printf("FATAL ERROR: ");
  vfprintf(stderr, error_message, va);
  printf("\n");
  va_end(va);
  exit(1);
}
