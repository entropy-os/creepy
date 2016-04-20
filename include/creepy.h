/*
** creepy.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:47:48 2016 Benjamin Grange
** Last update Wed Apr 20 04:19:29 2016 Benjamin Grange
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
  FLAG_MINIMAL		= 1000,
  FLAG_REFRESH
}			t_flags;

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
  const char		**targets;
  bool			help : 1;
  bool			version : 1;// -h
  bool			verbose : 1;// -v
  bool			refresh : 1;// -Sr
}			t_params;

typedef struct
{
  t_params		params;
}			t_creepy;

/* Utils functions */

void			print_error(const char *err);
int			print_errori(const char *err);
void			*print_errorn(const char *err);
void			cleanup(t_creepy *, int ret);

#endif /* !CREEPY_H_ */
