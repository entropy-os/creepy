/*
** cleanup.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 18:24:32 2016 Benjamin Grange
** Last update Sun Apr 17 22:09:11 2016 Benjamin Grange
*/

#include <stdlib.h>
#include "creepy.h"

void			cleanup(t_creepy *creepy, int ret)
{
  /*
  ** TODO : Free ressources.
  */
  (void)creepy;
  exit(ret);
}
