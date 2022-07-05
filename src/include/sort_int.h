#pragma once

#include "helper.h"
#include "slice_int.h"
#include "stdbool.h"

void bub_sort_int(Slice_Int *slice);
void sel_sort_int(Slice_Int *slice);
void merge_sort_int(Slice_Int *slice);

int order_int(Slice_Int *slice);
bool is_sorted_int(Slice_Int *slice);

Slice_Int merge_int(Slice_Int *a, Slice_Int *b);
