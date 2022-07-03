#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct slice_int
{
    int length;   // length of the slice
    int capacity; // capacity of the slice befor reallocating
    bool w_perm;  // write permission
    int *arr;     // pointer to the underlying array
} Slice_Int;

// Gets the element by the given index
static inline int get_int(Slice_Int *slice, int index)
{
    if (index < slice->length)
    {
        return slice->arr[index];
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}

// Sets the element by the given index.
static inline int set_int(Slice_Int *slice, int value, int index)
{
    if (index < slice->length)
    {
        return slice->arr[index];
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}

// Returns the length of the slice.
static inline int len_int(Slice_Int *slice)
{
    return slice->length;
}

// Returns the capacity of the slice.
static inline int cap_int(Slice_Int *slice)
{
    return slice->capacity;
}

// Frees the slice's underlying array.
// Only delete the original slice i.e. the slice containing the starting pointer.
static inline void delete_slice_int(Slice_Int *slice)
{
    if (slice->w_perm == true)
    {
        free(slice->arr);
        slice->arr = NULL;
    }
    else
    {
        fprintf(stderr, "Write denied!");
        exit(EXIT_FAILURE);
    }
}

// copy an array from another array of fixed length
static inline void copy_int(int *from, int *to, int length)
{
    for (int i = 0; i < length; i++)
    {
        to[i] = from[i];
    }
}

// Initialize an array to a value
static inline void init_int(int *arr, int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = value;
    }
}

// Increases the capacity when needed. *It does not decrease the capacity*
// Returns -1 if there is error in allocation. 0 otherwise.
static inline int check_capacity_int(Slice_Int *slice)
{
    if (slice->length == slice->capacity && slice->w_perm == true)
    {
        slice->capacity *= 2;
        int *new_arr = (int *)malloc(slice->capacity * sizeof(int));
        if (new_arr == NULL)
        {
            return -1;
        }
        copy_int(new_arr, slice->arr, slice->length);
        free(slice->arr);
        slice->arr = new_arr;
        return 0;
    }
    return 0;
}

Slice_Int new_slice_int(int capacity);
Slice_Int copy_slice_int(Slice_Int from);
Slice_Int slice_int_from(Slice_Int *slice, int start, int end, bool w_perm);
Slice_Int new_slice_int_from(Slice_Int *slice, int start, int end);
int append_int(Slice_Int *slice, int data);
int insert_int(Slice_Int *slice, int data, int index);
int delete_int(Slice_Int *slice, int index);
int search_int(Slice_Int *, int value);
int bsearch_int(Slice_Int *, int value);
int max_slice_int(Slice_Int *slice);
int min_slice_int(Slice_Int *slice);
void display_debug_int(Slice_Int *);
void display_int(Slice_Int *);