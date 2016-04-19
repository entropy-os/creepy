/*
** capsule.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:49:05 2016 Benjamin Grange
** Last update Tue Apr 19 15:13:14 2016 Matteo Melis
*/

#ifndef CAPSULE_H_
# define CAPSULE_H_

# define _GNU_SOURCE 1
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

typedef struct		s_capsule
{
  const char		*file_name;
  FILE			*fp;
  char			*buffer;
}			t_capsule;

/* Basic capsule file */

t_capsule		*capsule_load(const char *file_name);
void			capsule_del(t_capsule *capsule);
char			*capsule_get_data(t_capsule *, const char *, int);

/* Core capsule functions */


#endif /* !CAPSULE_H_ */
