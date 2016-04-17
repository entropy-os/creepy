/*
** creepy.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:47:48 2016 Benjamin Grange
** Last update Sun Apr 17 18:25:58 2016 Benjamin Grange
*/

#ifndef CREEPY_H_
# define CREEPY_H_

# include <stdio.h>
# include <stdbool.h>

# define TO_STR(x) #x
# define MACRO_TO_STR(macro) TO_STR(macro)

# define CREEPY_VERSION 0.1
# define CREEPY_VERSION_STR MACRO_TO_STR(CREEPY_VERSION)

/* Error handling functions */

void			print_error(char *err);
int			print_errori(char *err);
void			*print_errorn(char *err);

/* Free ressources and exit with value ret */

void			cleanup(int ret);


#endif /* !CREEPY_H_ */
