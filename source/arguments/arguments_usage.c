/*
** arguments_usage.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 18:26:42 2016 Benjamin Grange
** Last update Sun Apr 17 22:26:12 2016 Benjamin Grange
*/

#include "arguments.h"

void			arguments_usage_general(char *argv0)
{
  printf("usage: %s <operation> [...]\n", argv0);
  printf("operations:\n");
  printf("  {-h --help}\n");
  printf("  {-V --version}\n");
  printf("  {-S --sync}\n");
  printf("  {-R --remove}\n");
  printf("  {-L --list}\n");
}

void			arguments_usage_sync(char *argv0)
{
  printf("usage: %s {-S --sync} [options] <package(s)>\n", argv0);
}

void			arguments_usage_remove(char *argv0)
{
  printf("usage: %s {-R --remove} [options] <package(s)>\n", argv0);
}

void			arguments_usage_list(char *argv0)
{
  printf("usage: %s {-L --list} [options] <package(s)>\n", argv0);
}

void			arguments_usage(t_operation op,
					char *argv0)
{
  if (op == OP_SYNC)
    arguments_usage_sync(argv0);
  else if (op == OP_REMOVE)
    arguments_usage_remove(argv0);
  else if (op == OP_LIST)
    arguments_usage_list(argv0);
  else
    arguments_usage_general(argv0);
}
