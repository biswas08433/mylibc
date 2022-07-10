#pragma once
#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
// #include <float.h>

#include "helper.h"
#include "mystring.h"

// const double EPSILON = DBL_EPSILON;

int input_int(char *prompt, int min, int max);
double input_double(char *prompt, double min, double max);

#endif