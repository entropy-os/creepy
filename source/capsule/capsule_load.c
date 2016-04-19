/*
** capsule_load.c for capsule in /home/melis_m/code/github/creepy/source/capsule/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Fri Apr 15 18:08:03 2016 Matteo Melis
** Last update Tue Apr 19 14:15:27 2016 Matteo Melis
*/

#include "capsule.h"

static char		*file_read(t_capsule *cps)
{
  struct stat		sb;
  char			*buffer;

  if ((lstat(cps->file_name, &sb)) == -1)
    {
      perror("lstat");
      return (NULL);
    }
  if (!(buffer = malloc(sizeof(char) * (sb.st_size + 1))))
    exit(3);
  if ((fread(buffer, sizeof(char), sb.st_size, cps->fp))
      != (size_t)sb.st_size)
    {
      perror("read error");
      return (NULL);
    }
  buffer[sb.st_size - 1] = 0;
  return (buffer);
}

t_capsule		*capsule_load(const char *name)
{
  t_capsule		*cps;
  FILE			*fp;

  if (!(fp = fopen(name, "r")))
    {
      perror("fopen");
      return (NULL);
    }
  if (!(cps = malloc(sizeof(t_capsule))))
    {
      perror("malloc");
      return (NULL);
    }
  cps->file_name = name;
  cps->fp = fp;
  if (!(cps->buffer = file_read(cps)))
    return (NULL);
  return (cps);
}
