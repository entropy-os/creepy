/*
** init.c for creepy in /home/grange_c/creepy/source/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 01:55:53 2016 Benjamin Grange
** Last update Sun Apr 24 03:49:50 2016 Benjamin Grange
*/

#include <sys/stat.h>
#include <string.h>
#include "creepy.h"

int			init(t_creepy *creepy)
{
  struct stat		st;

  memset(creepy, 0, sizeof(t_creepy));

  // Main creepy directory
  if (stat(CREEPY_PATH, &st) == -1 && mkdir(CREEPY_PATH, 0755) != 0)
    {
      print_error("Can't create creepy main directory \"" CREEPY_PATH "\"\n");
      return (-1);
    }

  // Curl initialisation
  curl_global_init(CURL_GLOBAL_ALL);

  return (false);
}
