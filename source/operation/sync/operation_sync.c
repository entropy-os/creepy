/*
** operation_sync.c for creepy in /home/grange_c/creepy/source/operation/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 22:14:46 2016 Benjamin Grange
** Last update Wed Apr 20 04:30:05 2016 Benjamin Grange
*/

#include "operation_sync.h"

int			operation_sync(t_creepy *creepy)
{
  const char		**tar;

  tar = creepy->params.targets;
  printf("In operation_sync() ! Refresh : %i\n", creepy->params.refresh);
  printf("Targets:\n");
  while (*tar)
    {
      printf("%s\n", *tar);
      tar++;
    }
  return (0);
}
