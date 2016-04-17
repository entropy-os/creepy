/*
** arguments_parse_option.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 14:54:19 2016 Benjamin Grange
** Last update Sun Apr 17 18:58:24 2016 Benjamin Grange
*/

#include "arguments.h"

/*
** Parse operations from command-line arguments.
** If dryrun equals true, the operation is NOT changed.
*/
bool			arguments_parse_operation(t_params *params,
						  int opt, bool dryrun)
{
  switch(opt)
    {
      case 'S':
        if (dryrun) break;
      	params->op = (params->op != OP_DEFAULT ? 0 : OP_SYNC); break;
      case 'R':
        if (dryrun) break;
        params->op = (params->op != OP_DEFAULT ? 0 : OP_REMOVE); break;
      case 'L':
        if (dryrun) break;
        params->op = (params->op != OP_DEFAULT ? 0 : OP_LIST); break;
      case 'h':
        if (dryrun) break;
        params->help = 1; break;
      case 'V':
        if (dryrun) break;
        params->version = 1; break;
      default:
        return (true);
    }
  return (false);
}
