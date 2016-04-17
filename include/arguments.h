/*
** arguments.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:59:59 2016 Benjamin Grange
** Last update Sun Apr 17 19:03:35 2016 Benjamin Grange
*/

#ifndef ARGUMENTS_H_
# define ARGUMENTS_H_

# include <string.h>
# include "creepy.h"

typedef enum
{
  OP_DEFAULT = 1,
  OP_SYNC,
  OP_REMOVE,
  OP_LIST,
}			t_operation;

typedef struct		s_params
{
  t_operation		op;
  bool			help : 1;
  bool			version : 1;
}			t_params;

/* Basic arguments functions */

int		arguments_parse(t_params *, int, char *[]);
bool		arguments_parse_operation(t_params *, int, bool);

void		arguments_usage(t_operation, char *);
void		arguments_version();

#endif /* !ARGUMENTS_H_ */
