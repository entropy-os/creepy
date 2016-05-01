/*
** utils_humanize_size.c for creepy in /home/grange_c/creepy/source/utils/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Wed Apr 27 22:23:19 2016 Benjamin Grange
** Last update Wed Apr 27 22:30:13 2016 Benjamin Grange
*/

double			humanize_size(double bytes, const char **label)
{
  const char		*units[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
  int			unit_size = sizeof(units) / sizeof(char *);
  int			index;

  index = 0;
  while (index < unit_size - 1)
    {
      if (bytes <= 2048)
	break;
      bytes /= 1024.0;
      index++;
    }
  if (label)
    *label = units[index];
  return (bytes);
}
