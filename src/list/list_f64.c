#include "../include/list.h"
#include "../include/helper.h"
#include "../include/strconv.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

List list_new_f64(u32 capacity) {
    List temp = list_new(capacity, sizeof(f64));
    list_set_print_func(&temp, print_f64);
    return temp;
}

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_f64(List* self, f64 data) {
    return list_append(self, &data);
}

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_f64(List* self, f64 data, u32 index) {
    return list_insert(self, &data, index);
}

// Searches for the data. Returns -1 if not found.
u32 list_search_f64(List* self, f64 value) {
    for (u32 i = 0; i < self->length; i++) {
        f64 temp = list_get_f64(self, i);
        if (fabs(temp - value) <= DBL_EPSILON) {
            return i;
        }
    }
    return -1;
}

// TODO: NOT IMPLEMENTED
u32 list_bsearch_f64(List* self, f64 value) {
    // NOT IMPLEMENTED
    return 0;
}

// Returns the maximum element from the self.
f64 list_max_f64(List* self) {
    f64 t = DBL_MIN;
    for (u32 i = 0; i < self->length; i++) {
        f64 temp = list_get_f64(self, i);
        if (temp - t > DBL_EPSILON) {
            t = temp;
        }
    }
    return t;
}
// Returns the minimum element from the self.
f64 list_min_f64(List* self) {
    f64 t = DBL_MAX;
    for (u32 i = 0; i < self->length; i++) {
        f64 temp = list_get_f64(self, i);
        if (temp - t < DBL_EPSILON) {
            t = temp;
        }
    }
    return t;
}

// Gets the element by the given index.
f64 list_get_f64(List* self, u32 index) {
    return *(f64*)list_get(self, index);
}
// Sets the element by the given index.
void list_set_f64(List* self, f64 data, u32 index) {
    list_set(self, &data, index);
}