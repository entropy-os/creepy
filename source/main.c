/*
** main.c for creepy in /home/grange_c/creepy/source/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:54:27 2016 Benjamin Grange
** Last update Sun May  1 03:54:22 2016 Benjamin Grange
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "creepy.h"
#include "arguments.h"
#include "operation.h"

static int      	do_operation(t_creepy *creepy)
{
  int           	ret;

  ret = 0;
  switch (creepy->params.op)
    {
      case OP_SYNC:
        ret = operation_sync(creepy);
        break;
      case OP_REMOVE:
        ret = operation_remove(creepy);
        break;
      case OP_LIST:
        ret = operation_list(creepy);
        break;
      default:
        print_error("no operation specified (use -h for help)\n");
        return (-1);
    }
  return (ret);
}

/*
** Returns a repository or NULL on error.
*/
static t_repository     *create_repo(void)
{
  t_repository *repo = malloc(sizeof(t_repository));
  if (repo == NULL)
    return (NULL);
  repo->name = creepy_strdup("Creepy_Official_Repository");
  repo->url = creepy_strdup("http://download.thinkbroadband.com/5MB.zip");
  repo->next = NULL;
  if (repo->name == NULL || repo->url == NULL)
    return (NULL);
  return repo;
}

int			main(int argc, char *argv[])
{
  t_creepy		creepy;
  int			myuid = getuid();

  if (init(&creepy))
    goto cleanup_creepy_error;

  // TODO: Add auto-loading of repositories
  creepy.repo = create_repo();
  if (creepy.repo == NULL)
    {
      print_error("Failed to create the default repository\n");
      goto cleanup_creepy_error;
    }

  if (arguments_parse(&creepy, &creepy.params, argc, argv) != 0)
    goto cleanup_creepy_error;

  if (myuid > 0 && arguments_needs_root(&creepy.params))
    {
      print_error("you need to be root to perform this operation\n");
      goto cleanup_creepy_error;
    }

  if (do_operation(&creepy) != 0 )
    goto cleanup_creepy_error;

  cleanup(&creepy);
  return (EXIT_SUCCESS);

  cleanup_creepy_error:
  cleanup(&creepy);
  return (EXIT_FAILURE);
}
