#include "../include/sort.h"
#include "../include/helper.h"

#include <limits.h>

// TODO: Bubble Sort
void bub_sort(List* self) {}

// TODO: Selection Sort
void sel_sort_i32(List* self) {}

// TODO: NOT IMPLEMENTED
void merge_sort_i32(List* self) {
    // NOT IMPLEMENTED
}

// this return 2 if the self is not sorted; else returns the slope.
// -1 -> not descending order
// 0 -> same
// 1-> not ascending order
i32 order(List* self) {
    return 0;
}

// Returns TRUE if sorted; FALSE otherwise.
b8 is_sorted(List* self) {
    if (order(self) == 2) {
        return FALSE;
    }
    return TRUE;
}

// Merges two sorted slices and returns a new list.
void merge(List* a, List* b) {}
