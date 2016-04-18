/*
** capsule_get_data.c for  in /home/melis_m/code/github/creepy/source/capsule/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Fri Apr 15 19:01:47 2016 Matteo Melis
** Last update Sun Apr 17 11:36:32 2016 Matteo Melis
*/

#include "capsule.h"

char		*skip_spaces_newline(const char *s)
{
  char		*tmp;

  tmp = (char *)s;
//  while (*tmp && (isspace(*tmp) || *tmp == '\n'))
    while (*tmp && *tmp != '"')
    tmp++;
  return (tmp);
}

static char	*get_str(const char *data, int index)
{
  int		i;
  char		*ret;

  while (*data && (*data == '\n' || isspace(*data)))
    data++;
  if (index == 0 && data[0] != '"')
    {
      if (!(ret = strndup(data, (int)(strchr(data, '\n') - data))))
	exit(3);
    }
  else
    {
      i = -1;
      while (i != index)
	{
	  data = skip_spaces_newline(data);
	  data += (int)(strchr(data, '"') - data + 1);
	  //data = skip_spaces_newline(data);
	  data += *data == '"';
	  printf("oui : '%.10s'\n", data);
	  i += 1;
	}
      if (!(ret = strndup(data, (int)(strchr(data, '"') - data))))
	exit(3);
    }
  return (ret);
}

static char	*get_start(t_capsule *cps,
			   const char *data)
{
  char		*tmp;
  char		*data_eq;

  if (!(data_eq = malloc(sizeof(char) * (strlen(data) + 2))))
    exit(3);
  sprintf(data_eq, "%s=", data);
  tmp = cps->buffer;
  while (*tmp && (*(tmp - (tmp != cps->buffer)) != '\n'
		  || strncmp(tmp, data_eq, strlen(data))))
    tmp++;
  free(data_eq);
  if (!*tmp)
    return (NULL);
  return (tmp + strlen(data) + 1);
}

char		*capsule_get_data(t_capsule *cps,
				  const char *data,
				  int index)
{
  char		*tmp;

  tmp = get_start(cps, data);
  if (tmp == NULL)
    {
      fprintf(stderr, "No such value '%s' in %s.\n", data, cps->file_name);
      free(tmp);
      capsule_del(cps);
      exit(1);
    }
  tmp = get_str(tmp, index);
  return (tmp);
}
