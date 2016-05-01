/*
** creepy.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:47:48 2016 Benjamin Grange
** Last update Sun May  1 03:59:12 2016 Benjamin Grange
*/

#ifndef CREEPY_H_
# define CREEPY_H_

# include <stdbool.h>
# include <curl/curl.h>

# define STR(x) #x
# define XSTR(macro) STR(macro)
# define FORMAT(x, y) __attribute__ ((format (printf, x, y)))
# define CREEPY_VERSION 0.1
# define CREEPY_VERSION_STR XSTR(CREEPY_VERSION)
# define CREEPY_PATH "/etc/creepy"

typedef			enum
{
  FLAG_MINIMAL		= 1000,
  FLAG_REFRESH,
  FLAG_VERBOSE
}			t_flags;

typedef enum		e_operation
{
  OP_DEFAULT = 1,
  OP_SYNC,
  OP_REMOVE,
  OP_LIST,
}			t_operation;

typedef struct		s_repository
{
  char            	*name;
  char            	*url;
  struct s_repository	*next;
}			t_repository;

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
  t_repository		*repo;
}			t_creepy;

/*
** Returns -1 on error, 0 on success.
**
** A description of the error is printed on the error output.
** On error, the t_creepy must not be invalidated with cleanup().
*/
int			init(t_creepy *creepy);

/* Utils functions */

/*
** Prints an error message.
*/
void			print_error(const char *err, ...) FORMAT(1, 2);

/*
** Frees the ressources allocated in the given t_creepy.
**
** Invalidate the t_creepy.
*/
void			cleanup(t_creepy *creepy);

/*
** Prints the error message and exits with a non-zero status.
**
** Use only in case of fatal error.
*/
void    		die(const char *err, ...) __attribute__ ((noreturn));

/*
** Prints the fmt message using printf-like arguments only if the verbose
** argument has been choosen.
*/
void			verbose(const t_creepy *, const char *fmt, ...) FORMAT(2, 3);

/*
** Return the number of column in the terminal
*/
unsigned short		getcols(void);

/*
** Usefull string-management functions
*/
char			*creepy_strdup(const char *str);
char			*creepy_asprintf(const char *fmt, ...) FORMAT(1, 2);
double			humanize_size(double bytes, const char **label);
int			number_digits(size_t i);

#endif /* !CREEPY_H_ */
