/*
** operation_sync_refresh.c for creepy in /home/grange_c/creepy/source/operation/sync/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 01:18:38 2016 Benjamin Grange
** Last update Sun May  1 04:09:21 2016 Benjamin Grange
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "operation_sync.h"
#include "repository.h"
#include "download.h"

int			operation_sync_refresh(t_creepy *creepy)
{
  t_repository		*repo;
  t_dl_group		*group;

  repo = creepy->repo;
  verbose(creepy, "Refreshing repositories...");
  while (repo)
    {
      if (repository_create_main_dir(repo))
	return (-1);

      group = download_group_create();
      for (int i = 0; i < 10; i++) //FIXME Added this for debug
	{
	  char *test = creepy_asprintf("%s-%i", repo->name, rand());
	  download_group_add_file(group,
				  creepy_strdup(repo->url), test,
				  creepy_asprintf(CREEPY_PATH"/%s/package_list", repo->name));
	}
      download_group(group);
      download_group_destroy(group);
      repo = repo->next;
    }
  verbose(creepy, "Repositories are now up to date.");
  return (0);
}
