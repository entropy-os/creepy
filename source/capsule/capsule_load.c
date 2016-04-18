/*
** capsule_load.c for capsule in /home/melis_m/code/github/creepy/source/capsule/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Fri Apr 15 18:08:03 2016 Matteo Melis
** Last update Sat Apr 16 00:41:48 2016 Matteo Melis
*/

#include "capsule.h"

static char		*read_file(t_capsule *cps)
{
  struct stat		sb;
  char			*buffer;

  if ((lstat(cps->file_name, &sb)) == -1)
    {
      perror("lstat");
      exit(1);
    }
  if (!(buffer = malloc(sizeof(char) * (sb.st_size + 1))))
    exit(3);
  if ((fread(buffer, sizeof(char), sb.st_size, cps->fp))
      != (size_t)sb.st_size)
    {
      perror("read error");
      exit(1);
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
      exit(EXIT_FAILURE);
    }
  if (!(cps = malloc(sizeof(t_capsule))))
    {
      perror("Malloc");
      exit(EXIT_FAILURE);
    }
  cps->file_name = name;
  cps->fp = fp;
  cps->buffer = read_file(cps);
  return (cps);
}
