/*
** capsule.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:49:05 2016 Benjamin Grange
** Last update Fri Apr 15 18:05:08 2016 Benjamin Grange
*/

#ifndef CAPSULE_H_
# define CAPSULE_H_

# include <stdio.h>

typedef struct		s_capsule
{
  const char		*file_name;
  FILE			*file;
}			t_capsule;

/* Basic capsule file */

t_capsule		*capsule_load(const char *file_name);
void			capsule_del(t_capsule *capsule);
void			*capsule_get_data(t_capsule *, const char *, int);

/* Core capsule functions */

// TODO

#endif /* !CAPSULE_H_ */
