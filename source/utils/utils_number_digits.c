/*
** utils_number_digits.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun May  1 03:57:46 2016 Benjamin Grange
** Last update Sun May  1 03:59:03 2016 Benjamin Grange
*/

#include <stddef.h>

int			number_digits(size_t i)
{
  int			x;

  x = 1;
  while ((i /= 10))
    ++x;
  return (x);
}
