#include "../include/helper.h"

// Prints a line with newline.
void println(const char *line)
{
    printf("%s", line);
    printf("\n");
}

// Prints a line without newline.
void print(const char *line)
{
    printf("%s", line);
}

// Swaps two integers.
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Swaps teo floats.
void swap_float(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Swaps two doubles.
void swap_double(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

// a > b -> 1
// a = b -> 0
// a < b -> -1
int comp_int(int a, int b)
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
char *bool_str(bool b)
{
    char *t = "true";
    char *f = "false";

    return b ? t : f;
}

// Returns the maximum of two integers.
int max_int(int a, int b)
{
    return a >= b ? a : b;
}

// Returns the minimum of two integers.
int min_int(int a, int b)
{
    return a >= b ? b : a;
}

// Initialize an array to a value.
void init_int(int *arr, int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}

// Copy an array from another array of fixed length.
void copy_int(int *from, int *to, int length)
{
    for (int i = 0; i < length; i++)
    {
        to[i] = from[i];
    }
}

// Initialize an array to a value.
void init_double(double *arr, int length, double value)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}

// Copy an array from another array of fixed length.
void copy_double(double *from, double *to, int length)
{
    for (int i = 0; i < length; i++)
    {
        to[i] = from[i];
    }
}
