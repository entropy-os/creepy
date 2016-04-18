/*
** capsule_del.c for creeepy in /home/melis_m/code/github/creepy/source/capsule/
**
** Made by Matteo Melis
** Login   <melis_m@epitech.eu>
**
** Started on  Fri Apr 15 18:21:18 2016 Matteo Melis
** Last update Fri Apr 15 22:45:45 2016 Matteo Melis
*/

#include "capsule.h"

void		capsule_del(t_capsule *cps)
{
  fclose(cps->fp);
  free(cps->buffer);
  free(cps);
}
