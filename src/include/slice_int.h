#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#include "helper.h"

typedef struct slice_int
{
    int length;   // length of the slice
    int capacity; // capacity of the slice befor reallocating
    bool w_perm;  // write permission
    int *arr;     // pointer to the underlying array
} Slice_Int;

Slice_Int new_slice_int(int capacity);
Slice_Int copy_slice_int(Slice_Int from);
Slice_Int slice_int_from(Slice_Int *slice, int start, int end, bool w_perm);
Slice_Int new_slice_int_from(Slice_Int *slice, int start, int end);
int append_int(Slice_Int *slice, int data);
int insert_int(Slice_Int *slice, int data, int index);
int delete_int(Slice_Int *slice, int index);
int search_int(Slice_Int *slice, int value);
int bsearch_int(Slice_Int *slice, int value); // NOT IMPLEMENTED
int max_slice_int(Slice_Int *slice);
int min_slice_int(Slice_Int *slice);
void display_debug_int(Slice_Int *slice);
void display_int(Slice_Int *slice);

int get_int(Slice_Int *slice, int index);
int set_int(Slice_Int *slice, int value, int index);
int len_int(Slice_Int *slice);
int cap_int(Slice_Int *slice);
void delete_slice_int(Slice_Int *slice);

int inc_cap_int(Slice_Int *slice);