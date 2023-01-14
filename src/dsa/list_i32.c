#include "dsa/list_i32.h"
#include "helper.h"
#include "strconv.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

List list_new_i32(u32 capacity) {
    List temp = list_new(capacity, sizeof(i32));
    list_set_print_func(&temp, print_i32);
    return temp;
}

u32 list_append_i32(List* self, i32 data) {
    return list_append(self, &data);
}

u32 list_insert_i32(List* self, i32 data, u32 index) {
    return list_insert(self, &data, index);
}

u32 list_delete_i32(List* self, u32 index) {
    return list_delete(self, index);
}

u32 list_search_i32(List* self, i32 value) {
    for (u32 i = 0; i < self->length; i++) {
        i32 temp = *(i32*)list_get(self, i);
        if (temp == value) {
            return i;
        }
    }
    return -1;
}

// TODO binary search
u32 list_bsearch_i32(List* self, i32 value) {
    // Not IMPLEMENTED
    return 0;
}

i32 list_max_i32(List* self) {
    i32 t = INT_MIN;
    for (u32 i = 0; i < self->length; i++) {
        i32 temp = *(i32*)list_get(self, i);
        if (temp > t) {
            t = temp;
        }
    }
    return t;
}

i32 list_min_i32(List* self) {
    i32 t = INT_MAX;
    for (u32 i = 0; i < self->length; i++) {
        i32 temp = *(i32*)list_get(self, i);
        if (temp < t) {
            t = temp;
        }
    }
    return t;
}

i32 list_get_i32(List* self, u32 index) {
    return *(i32*)list_get(self, index);
}

void list_set_i32(List* self, i32 data, u32 index) {
    list_set(self, &data, index);
}