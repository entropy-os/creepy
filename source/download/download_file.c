/*
** download_file.c for creepy in /home/grange_c/creepy/source/download/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 24 02:51:34 2016 Benjamin Grange
** Last update Sun Apr 24 04:50:22 2016 Benjamin Grange
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include "download.h"

static int		download_progressbar(void *p,
					     curl_off_t dltotal, curl_off_t dlnow,
					     curl_off_t ultotal, curl_off_t ulnow)
{
  t_ftp_file		*ftp;
  double		percent;
  struct winsize	win;
  int			cur;
  int			i;

  (void)ultotal;(void)ulnow;
  ftp = (t_ftp_file *)p;
  if (dltotal > 0)
    {
      percent = dlnow / (double)dltotal;
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &win); //Get terminal size
      cur = (int)((64) * percent);

      //Printing progress bar
      int printname_size = printf("%s", ftp->print_name);
      printf("%*c", win.ws_col - 72 - printname_size, '[');
      for (i = 0; i < 64; i++)
	(i < cur) ? printf(">") : printf("_");
      printf("] %3i%% \r", (int)(percent * 100));
      fflush(stdout);
      ftp->print_once = true;
    }
  return (0);
}

static int		download_progressbar_old(void *p,
						 double dltotal, double dlnow,
						 double ultotal, double ulnow)
{
  return (download_progressbar(p,
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
  t_ftp_file		*out;

  out = (t_ftp_file *)stream;
  if(out && !out->stream)
    {
      out->stream = fopen(out->filename, "wb");
      if(!out->stream)
	return (-1);
    }
  return (fwrite(buffer, size, nmemb, out->stream));
}

bool			download_file(t_creepy *creepy,
				      const char *url,
				      const char *path,
				      const char *print_name)
{
  t_ftp_file		ftpfile;
  CURLcode		res;

  ftpfile.print_name = print_name;
  ftpfile.filename = path;
  ftpfile.stream = NULL;
  ftpfile.print_once = false;

  creepy->curl = curl_easy_init();
  if (creepy->curl)
    {
      curl_easy_setopt(creepy->curl, CURLOPT_URL, url);
      curl_easy_setopt(creepy->curl, CURLOPT_WRITEFUNCTION, download_write);
      curl_easy_setopt(creepy->curl, CURLOPT_WRITEDATA, &ftpfile);

      //Progress bar
      curl_easy_setopt(creepy->curl, CURLOPT_NOPROGRESS, 0L);
      curl_easy_setopt(creepy->curl, CURLOPT_PROGRESSFUNCTION, download_progressbar_old);
      curl_easy_setopt(creepy->curl, CURLOPT_PROGRESSDATA, &ftpfile);
      #if LIBCURL_VERSION_NUM >= 0x072000 //Old libcurl version compatibility
	  curl_easy_setopt(creepy->curl, CURLOPT_XFERINFOFUNCTION, download_progressbar);
          curl_easy_setopt(creepy->curl, CURLOPT_XFERINFODATA, &ftpfile);
      #endif

      res = curl_easy_perform(creepy->curl);
      curl_easy_cleanup(creepy->curl);

      if (res == CURLE_OK)
	download_progressbar(&ftpfile, 100, 100, 100, 100); //To print the 100% bar
      else if (!ftpfile.print_once)
	download_progressbar(&ftpfile, 100, 0, 100, 0); //To print the 0% bar when download didn't started
      if (ftpfile.print_once)
	printf("\n");

      if (ftpfile.stream)
	fclose(ftpfile.stream);
      return (res == CURLE_OK ? false : true);
    }
  return (true);
}
