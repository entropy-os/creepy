/*
** errors.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 18:06:26 2016 Benjamin Grange
** Last update Tue Apr 19 00:19:51 2016 Benjamin Grange
*/

#include <stdio.h>
#include "creepy.h"

void			print_error(const char *err)
{
  fprintf(stderr, "Error: %s\n", err);
}

int			print_errori(const char *err)
{
  print_error(err);
  return (1);
}

void			*print_errorn(const char *err)
{
  print_error(err);
  return (NULL);
}
