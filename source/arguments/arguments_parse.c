/*
** arguments_parse.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 18:20:12 2016 Benjamin Grange
** Last update Mon Apr 18 17:55:49 2016 Benjamin Grange
*/

#include <unistd.h>
#include <getopt.h>
#include "arguments.h"

int			arguments_parse(t_creepy *creepy, t_params *params,
					int argc, char *argv[])
{
  int			opt;
  int			option_index = 0;
  const char		*optstring = "SRLVh";

  params->op = OP_DEFAULT;
  static const struct option opts[] =
    {
      { "sync", no_argument, 0, 'S'},
      { "remove", no_argument, 0, 'R'},
      { "list", no_argument, 0, 'L'},
      { "version", no_argument, 0, 'V'},
      { "help", no_argument, 0, 'h'},
      { 0, 0, 0, 0}
    };

  // Parse operations
  while ((opt = getopt_long(argc, argv, optstring, opts, &option_index)) != (-1))
    {
      if (opt == '?')
	return (1);
      if (opt != 0)
	arguments_parse_operation(params, opt, false);
    }

  if (params->op == 0)
    return (print_errori("Only one operation may be used at a time"));
  if (params->help) {
      arguments_usage(creepy, params->op, argv[0]);
      cleanup(creepy, 0);
    }
  if (params->version) {
      arguments_version(creepy);
      cleanup(creepy, 0);
    }
  return (0);
}
