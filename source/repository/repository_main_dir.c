/*
** repository_main_dir.c for creepy in /home/grange_c/creepy/source/repository/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 02:24:45 2016 Benjamin Grange
** Last update Wed Apr 27 21:57:28 2016 Benjamin Grange
*/

#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "repository.h"

int			repository_create_main_dir(t_repository *repo)
{
  struct stat		st;
  char			*path;

  path = creepy_asprintf(CREEPY_PATH"/%s", repo->name);
  if (stat(path, &st) == -1 && mkdir(path, 0755) != 0)
    {
      free(path);
      print_error("Can't create directory \"%s\"\n", path);
      return (-1);
    }
  free(path);
  return (0);
}
