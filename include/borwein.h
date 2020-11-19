/*
** EPITECH PROJECT, 2018
** 110borwein.h
** File description:
** 110borwein.h
*/

#ifndef BORWEIN_H_
#define BORWEIN_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

#define USAGE ("README")
#define MY_EXIT_SUCCESS 0
#define MY_EXIT_ERROR 84

int borwein(int ac, char **av);
void compute_integrals(int nb);

#endif /* BORWEIN_H_ */
