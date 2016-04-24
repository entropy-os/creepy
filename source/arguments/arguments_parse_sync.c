/*
** arguments_parse_sync.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Apr 20 04:02:21 2016 Benjamin Grange
** Last update Sun Apr 24 15:08:55 2016 Benjamin Grange
*/

#include "arguments.h"

int			arguments_parse_sync(t_params *params, int opt)
{
  switch (opt)
    {
      case FLAG_REFRESH:
      case 'r':
        params->refresh = true;
        break;
      case FLAG_VERBOSE:
      case 'v':
        params->verbose = true;
        break;
      default:
	return (1);
    }
  return (0);
}
