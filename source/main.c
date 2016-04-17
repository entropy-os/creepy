/*
** main.c for creepy in /home/grange_c/creepy/source/
**
** Made by Benjamin Grange
** Login   <grange_c@epitech.net>
**
** Started on  Fri Apr 15 17:54:27 2016 Benjamin Grange
** Last update Sun Apr 17 19:05:46 2016 Benjamin Grange
*/

#include <string.h>
#include "arguments.h"

int			main(int argc, char *argv[])
{
  t_params		params;

  if (!arguments_parse(&params, argc, argv))
    printf("Operation : %i\n", params.op);
 }
