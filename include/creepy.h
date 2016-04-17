/*
** creepy.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:47:48 2016 Benjamin Grange
** Last update Sun Apr 17 22:28:38 2016 Benjamin Grange
*/

#ifndef CREEPY_H_
# define CREEPY_H_

# include <stdio.h>
# include <stdbool.h>

# define TO_STR(x) #x
# define MACRO_TO_STR(macro) TO_STR(macro)

# define CREEPY_VERSION 0.1
# define CREEPY_VERSION_STR MACRO_TO_STR(CREEPY_VERSION)

typedef			enum
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
  bool			verbose : 1;
}			t_params;

typedef struct
{
  t_params		params;
}			t_creepy;

/* Utils functions */

void			print_error(char *err);
int			print_errori(char *err);
void			*print_errorn(char *err);
void			cleanup(t_creepy *, int ret);

#endif /* !CREEPY_H_ */
