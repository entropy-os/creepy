/*
** operation_sync_refresh.c for creepy in /home/grange_c/creepy/source/operation/sync/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 01:18:38 2016 Benjamin Grange
** Last update Sun Apr 24 16:03:16 2016 Benjamin Grange
*/

#define _GNU_SOURCE //FIXME
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "operation_sync.h"
#include "repository.h"
#include "download.h"

static char		*get_packagelist_filename(t_repository *repo)
{
  char			*path;

  asprintf(&path, CREEPY_PATH"/%s/package_list", repo->name);
  if (!path)
    {
      die("asprintf() failed (Not enough memory?)\n");
    }
  return (path);
}

int			operation_sync_refresh(t_creepy *creepy)
{
  t_repository		*repo;
  char			*dest_path;

  repo = creepy->repo;
  verbose(creepy, "Refreshing repositories...");
  while (repo)
    {
      if (repository_create_main_dir(repo))
	return (-1);

      dest_path = get_packagelist_filename(repo);

      for (int i = 0; i < 3; i++) //FIXME : For debug
      if (download_file(creepy, repo->url, dest_path, repo->name))
	{
	  print_error("Failed while trying to refresh "
                      "repository \"%s\"\n", repo->name);
          return (-1);
	}
      free(dest_path);
      repo = repo->next;
    }
  return (0);
}
