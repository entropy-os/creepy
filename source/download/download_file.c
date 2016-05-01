/*
** download_file.c for creepy in /home/grange_c/creepy/source/download/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 02:51:34 2016 Benjamin Grange
** Last update Sun May  1 04:07:11 2016 Benjamin Grange
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include "download.h"

/* Draw the progressbar and the percentage (Eg: [>>>>----]  50%)*/
static void		download_print_progressbar(t_dl_group *group,
						   double ratio, int proglen)
{
  /* Len : 1 ('[') + 1 (']') + 6 (" 100% ")*/
  int			barlen = ((proglen > 8) ? proglen - 8 : 0);
  double		download_speed;
  int			i;

  download_speed = 0;
  if (barlen >= 50 && ratio > 0.01
      && curl_easy_getinfo(group->actual->curl,
			   CURLINFO_SPEED_DOWNLOAD, &download_speed) == CURLE_OK
      && download_speed > 0)
    {
      const char	*speed_unit;

      download_speed = humanize_size(download_speed, &speed_unit);
      if (download_speed < 9.995)
	printf("%4.2f %c/s ", download_speed, speed_unit[0]);
      else if (download_speed < 99.95)
	printf("%4.1f %c/s ", download_speed, speed_unit[0]);
      else
	printf("%4.f %c/s ", download_speed, speed_unit[0]);
      barlen -= 9;
    }
  if (barlen > 0)
    {
      putchar('[');
      i = barlen;
      while (i > 0)
	{
	  putchar((i > barlen - ratio * barlen) ? '>' : '-');
	  --i;
	}
      putchar(']');
    }
  if (proglen >= 6)
    printf(" %3i%% \r", (int)(ratio * 100.0));
}

static int		download_callback(void *p,
					  curl_off_t dltotal, curl_off_t dlnow,
					  curl_off_t ultotal, curl_off_t ulnow)
{
  t_dl_group		*group;
  unsigned char		cols;
  int			infolen;
  int			digits;

  (void)ultotal;(void)ulnow;// We are not uploading datas
  group = (t_dl_group *)p;

  cols = getcols();
  infolen = cols * 6 / 10;
  if (infolen < 50)
    infolen = 50;
  digits = number_digits(group->nb_file);
  printf("(%*zu/%*zu) %s%-*s", digits, group->actual->id, digits, group->nb_file,
	 group->actual->print_name,
	 infolen - 4 - 2 * digits - (int)strlen(group->actual->print_name), "");
  if (dltotal > 0.0)
    download_print_progressbar(group, dlnow / (double)dltotal, cols - infolen);
  else
    download_print_progressbar(group, 0, cols - infolen);
  putchar('\r');
  fflush(stdout);
  return (0);
}

static int		download_callback_old(void *p,
					      double dltotal, double dlnow,
					      double ultotal, double ulnow)
{
  return (download_callback(p,
			    (curl_off_t)dltotal,
			    (curl_off_t)dlnow,
			    (curl_off_t)ultotal,
			    (curl_off_t)ulnow));
}

static size_t		download_write(void *buffer,
				       size_t size,
				       size_t nmemb,
				       void *stream)
{
  t_dl_file		*file;

  file = (t_dl_file *)stream;
  if (file && !file->stream)
    {
      file->stream = fopen(file->filename, "wb");
      if(!file->stream)
	return (-1);
    }
  return (fwrite(buffer, size, nmemb, file->stream));
}

int			download_file(t_dl_group *group, t_dl_file *file)
{
  CURLcode		res;

  file->curl = curl_easy_init();
  if (!file->curl)
    die("curl_easy_init() failed");

  curl_easy_setopt(file->curl, CURLOPT_URL, file->url);
  curl_easy_setopt(file->curl, CURLOPT_WRITEFUNCTION, download_write);
  curl_easy_setopt(file->curl, CURLOPT_WRITEDATA, file);

  //Progress bar
  curl_easy_setopt(file->curl, CURLOPT_NOPROGRESS, 0L);
  curl_easy_setopt(file->curl, CURLOPT_PROGRESSFUNCTION, download_callback_old);
  curl_easy_setopt(file->curl, CURLOPT_PROGRESSDATA, group);
#if LIBCURL_VERSION_NUM >= 0x072000 //Recent libcurl version compatibility
  curl_easy_setopt(file->curl, CURLOPT_XFERINFOFUNCTION, download_callback);
  curl_easy_setopt(file->curl, CURLOPT_XFERINFODATA, group);
#endif

  res = curl_easy_perform(file->curl);
  curl_easy_cleanup(file->curl);
  printf("\n");
  if (file->stream)
    fclose(file->stream);
  return (res == CURLE_OK ? 0 : -1);
}
