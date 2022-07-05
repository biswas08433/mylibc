#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <stdbool.h>

#include "helper.h"

typedef struct slice_double
{
    int length;   // length of the slice
    int capacity; // capacity of the slice before it reallocates
    bool w_perm;  // write permission
    double *arr;  // pointer to the underlying array
} Slice_Double;

double epsilon = FLT_EPSILON;

Slice_Double new_slice_double(int capacity);
Slice_Double copy_slice_double(Slice_Double from);
Slice_Double slice_double_from(Slice_Double *slice, int start, int end, bool w_perm);
Slice_Double new_slice_double_from(Slice_Double *slice, int start, int end);

int append_double(Slice_Double *slice, double data);
int insert_double(Slice_Double *slice, double data, int index);
int delete_double(Slice_Double *slice, int index);

int search_double(Slice_Double *slice, double value);
int bsearch_double(Slice_Double *slice, double value); // NOT IMPLEMENTED

int max_slice_double(Slice_Double *slice);
int min_slice_double(Slice_Double *slice);

void display_debug_double(Slice_Double *slice);
void display_double(Slice_Double *slice);

int get_double(Slice_Double *slice, int index);
int set_double(Slice_Double *slice, double value, int index);

int len_double(Slice_Double *slice);
int cap_double(Slice_Double *slice);

void delete_slice_double(Slice_Double *slice);

int inc_cap_double(Slice_Double *slice);