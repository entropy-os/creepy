/*
** arguments_version.c for creepy in /home/grange_c/creepy/source/arguments/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Sun Apr 17 18:29:50 2016 Benjamin Grange
** Last update Sun Apr 17 22:26:41 2016 Benjamin Grange
*/

#include "arguments.h"

void			arguments_version(t_creepy *creepy)
{
  printf("Creepy v%s\n", CREEPY_VERSION_STR);
  printf("Copyright (C) 2016 - Creepy and Entropy development team\n");
}
