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

static void     usage_general(const char *program_name)
{
  printf("usage: %s <operation> [...]\n", program_name);
  printf("operations:\n");
  printf("  {-h --help}\n");
  printf("  {-V --version}\n");
  printf("  {-S --sync}\n");
  printf("  {-R --remove}\n");
  printf("  {-L --list}\n");
}

static void     usage_sync(const char *program_name)
{
  printf("usage: %s {-S --sync} [options] <package(s)>\n", program_name);
}

static void     usage_remove(const char *program_name)
{
  printf("usage: %s {-R --remove} [options] <package(s)>\n", program_name);
}

static void     usage_list(const char *program_name)
{
  printf("usage: %s {-L --list} [options] <package(s)>\n", program_name);
}

void            arguments_print_usage(t_creepy *creepy,
                                      t_operation op,
                                      const char *program_name)
{
  switch (op)
    {
    case OP_SYNC:
      usage_sync(program_name);
    case OP_REMOVE:
      usage_remove(program_name);
    case OP_LIST:
      usage_list(program_name);
    default:
      usage_general(program_name);
    }
  cleanup(creepy, 0);
}
