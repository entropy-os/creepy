/*
** capsule_get_data.c for  in /home/melis_m/code/github/creepy/source/capsule/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Fri Apr 15 19:01:47 2016 Matteo Melis
** Last update Tue Apr 19 14:45:17 2016 Matteo Melis
*/

#include "capsule.h"

static char	*skip_spaces_newline(const char *s)
{
  char		*tmp;

  tmp = (char *)s;
//  while (*tmp && (isspace(*tmp) || *tmp == '\n'))

  while (*tmp && *tmp != '"')
    tmp++;
  return (tmp);
}

static char	*check_no_quotes(const char *data, int index)
{
  int		var_len;
  char		*ret;

  if (index == 0 && data[0] != '"')
    {
      var_len = (int)(strchr(data, '\n') - data);
      if (var_len == 0)
	var_len = strlen(data) - *data;
      if (!(ret = strndup(data, var_len)))
	exit(3);
      return (ret);
    }
  return (NULL);
}

static int	check_if_last(const char *s, const char *data)
{
  const char	*tmp;

  tmp = data + (int)(strchrnul(data, '"') - data);
  while (tmp != s)
    {
      if (*tmp == '=')
	return (1);
      tmp--;
    }
  return (0);
}

static char	*get_str(const char *s, int index)
{
  int		i;
  char		*ret;
  const char 	*data;

  data = s;
   //while (*data && (*data == '\n' || isspace(*data)))

  while (isspace(*data) && *data != '"')
     data++;
  if (!(ret = check_no_quotes(data, index)))
    {
      data += *data == '"';
      i = 0;
      while (i != index)
	{
	  while (!isalpha(*data) && *data != '"')
	    data++;
	  data += (int)(strchr(data, '"') - data);
	  data += *data == '"';
	  while (!isalpha(*data) && *data != '"')
	    data++;
	  data += *data == '"';
//	  printf("oui : '%.30s'\n", data);
	  i += 1;
	  if (check_if_last(s, data))
	    return (NULL);
	}
      if (!(ret = strndup(data, (int)(strchrnul(data, '"') - data))))
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
  while (*tmp && strncmp(tmp, data_eq, strlen(data)))
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
      return (NULL);
    }
  tmp = get_str(tmp, index);
  return (tmp);
}
