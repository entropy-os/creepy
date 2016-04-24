/*
** utils_verbose.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 15:37:24 2016 Benjamin Grange
** Last update Sun Apr 24 15:40:33 2016 Benjamin Grange
*/

#include "creepy.h"

void			verbose(t_creepy *creepy, const char *fmt)
{
  if (creepy->params.verbose)
    printf("%s\n", fmt);
}
