/*
** download_group.c for creepy in /home/grange_c/creepy/source/download/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun May  1 03:24:55 2016 Benjamin Grange
** Last update Sun May  1 03:57:24 2016 Benjamin Grange
*/

#include <stdlib.h>
#include <string.h>
#include "download.h"

t_dl_group		*download_group_create(void)
{
  t_dl_group		*group;

  group = malloc(sizeof(t_dl_group));
  if (!group)
    die("malloc() failed! (Not enough memory?)\n");
  memset(group, 0, sizeof(t_dl_group));
  return (group);
}

void			download_group_add_file(t_dl_group *group,
						char *url,
						char *print_name,
						char *filename)
{
  t_dl_file		*file;

  file = malloc(sizeof(t_dl_file));
  if (!file)
    die("malloc() failed! (Not enough memory?)\n");
  file->url = url;
  file->print_name = print_name;
  file->filename = filename;
  file->stream = NULL;
  file->next = NULL;
  file->curl = NULL;
  if (group->last)
    group->last->next = file;
  group->last = file;
  if (!group->file_list)
    group->file_list = file;
  group->nb_file++;
  file->id = group->nb_file;
}

void			download_group_destroy(t_dl_group *group)
{
  t_dl_file		*file;
  t_dl_file		*tmp;

  if (group)
    {
      file = group->file_list;
      while (file)
	{
	  tmp = file->next;
	  free(file->url);
	  free(file->print_name);
	  free(file->filename);
	  free(file);
	  file = tmp;
	}
      free(group);
    }
}

int			download_group(t_dl_group *group)
{
  t_dl_file		*file;

  file = group->file_list;
  while (file)
    {
      group->actual = file;
      if (download_file(group, file) == -1)
	{
	  fprintf(stderr, "Failed to download file \"%s\" (url: %s)\n", file->print_name, file->url);
	  return (-1);
	}
      file = file->next;
    }
  return (0);
}
