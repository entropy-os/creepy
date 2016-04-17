/*
** arguments.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:59:59 2016 Benjamin Grange
** Last update Sun Apr 17 22:26:45 2016 Benjamin Grange
*/

#ifndef ARGUMENTS_H_
# define ARGUMENTS_H_

# include "creepy.h"

/* Arguments parsing functions */

int		arguments_parse(t_creepy *, t_params *, int, char *[]);
bool		arguments_parse_operation(t_params *, int, bool);


/* Utils functions */

void		arguments_usage(t_creepy *, t_operation, char *);
void		arguments_version(t_creepy *);
bool		arguments_needs_root(t_params *params);

#endif /* !ARGUMENTS_H_ */
