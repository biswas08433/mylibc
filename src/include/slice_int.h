#pragma once
#ifndef SLICE_INT_H
#define SLICE_INT_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#include "helper.h"

typedef struct sliceInt
{
    int length;   // length of the slice
    int capacity; // capacity of the slice befor reallocating
    bool w_perm;  // write permission
    int *arr;     // pointer to the underlying array
} SliceInt;

SliceInt new_slice_int(int capacity);
SliceInt copy_slice_int(SliceInt from);
SliceInt slice_int_from(SliceInt *slice, int start, int end, bool w_perm);
SliceInt new_slice_int_from(SliceInt *slice, int start, int end);

int append_int(SliceInt *slice, int data);
int insert_int(SliceInt *slice, int data, int index);
int delete_int(SliceInt *slice, int index);
int search_int(SliceInt *slice, int value);
int bsearch_int(SliceInt *slice, int value); // NOT IMPLEMENTED

int max_slice_int(SliceInt *slice);
int min_slice_int(SliceInt *slice);
void display_debug_int(SliceInt *slice);
void display_int(SliceInt *slice);

int get_int(SliceInt *slice, int index);
void set_int(SliceInt *slice, int value, int index);

int len_int(SliceInt *slice);
int cap_int(SliceInt *slice);

void delete_slice_int(SliceInt *slice);

int inc_cap_int(SliceInt *slice);

#endif