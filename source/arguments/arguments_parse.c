/*
** arguments_parse.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 18:20:12 2016 Benjamin Grange
** Last update Sun Apr 24 15:44:16 2016 Benjamin Grange
*/

#include <unistd.h>
#include <getopt.h>
#include "arguments.h"

int			arguments_parse(t_creepy *creepy, t_params *params,
					int argc, char *argv[])
{
  int			result;
  int			opt;
  int			option_index = 0;
  const char		*optstring = "SRLVhrv";

  params->op = OP_DEFAULT;
  static const struct option opts[] =
    {
      { "sync", no_argument, 0, 'S'},
      { "remove", no_argument, 0, 'R'},
      { "list", no_argument, 0, 'L'},
      { "version", no_argument, 0, 'V'},
      { "help", no_argument, 0, 'h'},

      { "refresh",	no_argument, 0, FLAG_REFRESH},
      { "verbose",	no_argument, 0, FLAG_VERBOSE},
      { 0, 0, 0, 0}
    };

  // Parse operations (Like the -S in -Sr)
  while ((opt = getopt_long(argc, argv, optstring, opts, &option_index)) != (-1))
    {
      if (opt == '?')
	return (1);
      if (opt != 0)
	arguments_parse_operation(params, opt, false);
    }

  if (params->op == 0)
    return (print_errori("Only one operation may be used at a time\n"));
  if (params->help) {
      arguments_usage(creepy, params->op, argv[0]);
      cleanup(creepy, 0);
    }
  if (params->version) {
      arguments_version(creepy);
      cleanup(creepy, 0);
    }

  //Parse operations parameters. (Like the -r in -Sr)
  optind = 1;
  while ((opt = getopt_long(argc, argv, optstring, opts, &option_index)) != (-1))
    {
      if (opt == '?')
	return (1);
      else if (opt == 0 || arguments_parse_operation(params, opt, true) == 0)
	continue;
      switch (creepy->params.op)
	{
	  case OP_SYNC:
	    result = arguments_parse_sync(&creepy->params, opt);
	    break;
	  default:
	    result = 1;
	    break;
	}
      if (result != 0) //The flag exists, but it's not in the actual operation.
	{
	  if(opt < FLAG_MINIMAL)
	    fprintf(stderr, "invalid option '-%c' "
		    "(use -h or --help for help)\n", opt);
	  else
	    fprintf(stderr, "invalid option '--%s' "
		    "(use -h or --help for help)\n",
		    opts[option_index].name);
	  return (result);
	}
    }
  creepy->params.targets = (const char **)argv + optind;
  /*
  ** TODO: Add flag conflicts verifications
  */
  return (0);
}
