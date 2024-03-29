#include "helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Swaps two integers.
void swap_i32(void *a, void *b)
{
    i32 temp = *(i32 *)a;
    *(i32 *)a = *(i32 *)b;
    *(i32 *)b = temp;
}

// Swaps two doubles.
void swap_f64(void *a, void *b)
{
    f64 temp = *(f64 *)a;
    *(f64 *)a = *(f64 *)b;
    *(f64 *)b = temp;
}

// Swaps two doubles.
void swap(void *a, void *b, i32 size)
{
    void *temp = calloc(1, size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
    temp = NULL;
}

// a > b -> 1
// a = b -> 0
// a < b -> -1
i32 compare_i32(const void *a, const void *b)
{

    i32 _a = *(i32 *)a;
    i32 _b = *(i32 *)b;
    if (_a > _b)
    {
        return 1;
    }
    else if (_a < _b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

i32 compare_f64(const void *a, const void *b)
{
    f64 _a = *(f64 *)a;
    f64 _b = *(f64 *)b;
    if (_a - _b > EPSILON)
    {
        return 1;
    }
    else if (_a - _b > -EPSILON)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Returns the maximum of two integers.
i32 max_i64(i32 a, i32 b)
{
    return a >= b ? a : b;
}

// Returns the minimum of two integers.
i32 min_i64(i32 a, i32 b)
{
    return a >= b ? b : a;
}

// Initialize an array to a value.
void init_i32(i32 *arr, u32 length, i32 value)
{
    for (i32 i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}
void init_f64(f64 *arr, u32 length, f64 value)
{
    for (i32 i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}
void init_char(char *arr, u32 length, char value)
{
    for (i32 i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}

void init_bool(b8 *arr, u32 length, b8 value)
{
    for (i32 i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}

// Copy an array from another array of fixed length.
void copy_i32(i32 *src, i32 *dest, u32 length)
{
    for (i32 i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
}

// Initialize an array to a value.

// Copy an array from another array of fixed length.
void copy_f64(f64 *src, f64 *dest, u32 length)
{
    for (i32 i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
}

void copy_char(char *from, char *to, u32 length)
{
    memcpy(to, from, length);
}

void print_i32(const void *data)
{
    printf("%d", *(i32 *)data);
}

void print_f64(const void *data)
{
    printf("%.15g", *(f64 *)data);
}
void print_b8(const void *data)
{
    printf("%c", *(b8 *)data);
}
void print_string(const void *data)
{
    printf("%s", (char *)data);
}
