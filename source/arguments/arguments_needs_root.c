/*
** arguments_needs_root.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 19:49:05 2016 Benjamin Grange
** Last update Sun Apr 17 19:49:07 2016 Benjamin Grange
*/

#include "arguments.h"

bool			arguments_needs_root(t_params *params)
{
  switch (params->op)
    {
      case OP_SYNC:
        return (true);
      case OP_REMOVE:
        return (true);
      default:
        return (false);
    }
}
