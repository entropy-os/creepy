/*
** arguments.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:59:59 2016 Benjamin Grange
** Last update Wed Apr 20 04:08:07 2016 Benjamin Grange
*/

#ifndef ARGUMENTS_H_
# define ARGUMENTS_H_

# include "creepy.h"

/* Arguments parsing functions */

/*
** Returns 0 on success, -1 on error
*/
int		arguments_parse(t_creepy *, t_params *, int, char *[]);
bool		arguments_parse_operation(t_params *, int, bool);
int		arguments_parse_sync(t_params *params, int opt);

/* Utils functions */

void		arguments_print_usage(t_operation op,
                                      const char *program_name);

void		arguments_version(t_creepy *);
bool		arguments_needs_root(t_params *params);

#endif /* !ARGUMENTS_H_ */
