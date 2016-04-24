/*
** download.h for creepy in /home/grange_c/creepy/include/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 02:52:29 2016 Benjamin Grange
** Last update Sun Apr 24 04:50:13 2016 Benjamin Grange
*/

#ifndef DOWNLOAD_H_
# define DOWNLOAD_H_

# include <curl/curl.h>
# include "creepy.h"

typedef struct		s_ftp_file
{
  const char		*print_name;
  const char		*filename;
  FILE			*stream;
  bool			print_once;
}			t_ftp_file;

bool			download_file(t_creepy *,
				      const char *u,
				      const char *p,
				      const char *print_name);

#endif /* !DOWNLOAD_H_ */
