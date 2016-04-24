/*
** operation_sync.c for creepy in /home/grange_c/creepy/source/operation/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 22:14:46 2016 Benjamin Grange
** Last update Sun Apr 24 15:36:07 2016 Benjamin Grange
*/

#include "operation_sync.h"

int			operation_sync(t_creepy *creepy)
{
  if (creepy->params.refresh && operation_sync_refresh(creepy))
    return (1);
  return (0);
}
