#pragma once
#ifndef SLICE_DBL_H
#define SLICE_DBL_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>

#include "helper.h"

typedef struct sliceDbl
{
    int length;   // length of the slice
    int capacity; // capacity of the slice before it reallocates
    bool w_perm;  // write permission
    double *arr;  // pointer to the underlying array
} SliceDbl;

SliceDbl new_slice_dbl(int capacity);
SliceDbl copy_slice_dbl(SliceDbl from);
SliceDbl slice_dbl_from(SliceDbl *slice, int start, int end, bool w_perm);
SliceDbl new_slice_dbl_from(SliceDbl *slice, int start, int end);

int append_dbl(SliceDbl *slice, double data);
int insert_dbl(SliceDbl *slice, double data, int index);
int delete_dbl(SliceDbl *slice, int index);

int search_dbl(SliceDbl *slice, double value);
int bsearch_dbl(SliceDbl *slice, double value); // NOT IMPLEMENTED

int max_slice_dbl(SliceDbl *slice);
int min_slice_dbl(SliceDbl *slice);

void display_debug_dbl(SliceDbl *slice);
void display_dbl(SliceDbl *slice);

double get_dbl(SliceDbl *slice, int index);
void set_dbl(SliceDbl *slice, double value, int index);

int len_dbl(SliceDbl *slice);
int cap_dbl(SliceDbl *slice);

void delete_slice_dbl(SliceDbl *slice);

int inc_cap_dbl(SliceDbl *slice);

#endif