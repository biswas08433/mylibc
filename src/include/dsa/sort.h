#pragma once

#include "defines.h"
#include "dsa/list.h"

// void bub_sort(List* self);
// void sel_sort(List* self);
// void merge_sort(List* self);

int order(List* self);
b8 is_sorted(List* self);

void merge(List* a, List* b);