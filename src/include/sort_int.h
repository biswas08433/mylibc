#pragma once
#ifndef SORT_H
#define SORT_H

#include "helper.h"
#include "slice_int.h"
#include "stdbool.h"

void bub_sort_int(SliceInt *slice);
void sel_sort_int(SliceInt *slice);
void merge_sort_int(SliceInt *slice);

int order_int(SliceInt *slice);
bool is_sorted_int(SliceInt *slice);

SliceInt merge_int(SliceInt *a, SliceInt *b);

#endif