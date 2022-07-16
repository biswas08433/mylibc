#pragma once

#include "defines.h"
#include "slice_i32.h"

void bub_sort_i32(Slice_i32 *self);
void sel_sort_i32(Slice_i32 *self);
void merge_sort_i32(Slice_i32 *self);

int order_i32(Slice_i32 *self);
b8 is_sorted_i32(Slice_i32 *self);

Slice_i32 merge_i32(Slice_i32 *a, Slice_i32 *b);