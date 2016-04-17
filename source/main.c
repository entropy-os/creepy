/*
** main.c for creepy in /home/grange_c/creepy/source/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:54:27 2016 Benjamin Grange
** Last update Sun Apr 17 22:28:22 2016 Benjamin Grange
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "creepy.h"
#include "arguments.h"
#include "operation.h"

int			main(int argc, char *argv[])
{
  t_creepy		creepy;
  int			ret;
  int			myuid = getuid();

  memset(&creepy, 0, sizeof(t_creepy));
  ret = arguments_parse(&creepy, &creepy.params, argc, argv);
  if (ret != 0)
    cleanup(&creepy, ret);
  if (myuid > 0 && arguments_needs_root(&creepy.params))
    {
      print_error("you need to be root to perform this operation");
      cleanup(&creepy, 1);
    }
  switch (creepy.params.op)
    {
      case OP_SYNC:
        ret = operation_sync(&creepy);
        break;
      case OP_REMOVE:
        ret = operation_remove(&creepy);
        break;
      case OP_LIST:
        ret = operation_list(&creepy);
        break;
      default:
      print_error("no operation specified (use -h for help)");
      ret = EXIT_FAILURE;
    }
  cleanup(&creepy, ret);
  return (EXIT_SUCCESS); /* Not reached */
}