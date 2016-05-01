/*
** download.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 02:52:29 2016 Benjamin Grange
** Last update Sun May  1 03:57:12 2016 Benjamin Grange
*/

#ifndef DOWNLOAD_H_
# define DOWNLOAD_H_

# include <curl/curl.h>
# include "creepy.h"

typedef struct		s_dl_file
{
  size_t		id;
  char			*url;
  char			*print_name;
  char			*filename;
  FILE			*stream;
  CURL			*curl;
  struct s_dl_file	*next;
}			t_dl_file;

typedef struct		s_dl_group
{
  size_t		nb_file;
  t_dl_file		*file_list;
  t_dl_file		*last;
  t_dl_file		*actual;
}			t_dl_group;

t_dl_group		*download_group_create(void);
void			download_group_destroy(t_dl_group *group);
void			download_group_add_file(t_dl_group *group,
						char *url,
						char *print_name,
						char *filename);
/*
** Returns -1 on error, 0 on success.
*/
int			download_file(t_dl_group *, t_dl_file *);
int			download_group(t_dl_group *group);

#endif /* !DOWNLOAD_H_ */
