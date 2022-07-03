#pragma once

#include <stdio.h>
#include <stdbool.h>

// Prints a line with newline.
static inline void println(const char *line)
{
    printf("%s", line);
    printf("\n");
}

// Prints a line without newline.
static inline void print(const char *line)
{
    printf("%s", line);
}

// Swaps two integers.
static inline void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swaps teo floats.
static inline void swap_float(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Swaps two doubles.
static inline void swap_double(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

// a > b -> 1
// a = b -> 0
// a < b -> -1
static inline int comp_int(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Returns the string version of bool value.
static inline char *bool_str(bool b)
{
    char *t = "true";
    char *f = "false";

    return b ? t : f;
}

// Returns the maximum of two integers.
static inline int max_int(int a, int b)
{
    return a >= b ? a : b;
}

// Returns the minimum of two integers.
static inline int min_int(int a, int b)
{
    return a >= b ? b : a;
}