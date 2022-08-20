#include "../include/list.h"
#include "../include/helper.h"
#include "../include/strconv.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

List list_new_i32(u32 capacity) {
    List temp = list_new(capacity, sizeof(i32));
    temp.t = I32;
    list_set_print_func(&temp, print_i32);
    return temp;
}

u32 list_append_i32(List* self, i32 data) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    return list_append(self, &data);
}

u32 list_insert_i32(List* self, i32 data, u32 index) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    return list_insert(self, &data, index);
}

u32 list_search_i32(const List* self, i32 value) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    for (u32 i = 0; i < self->length; i++) {
        i32 temp = *(i32*)list_get(self, i);
        if (temp == value) {
            return i;
        }
    }
    return -1;
}

// TODO binary search
u32 list_bsearch_i32(const List* self, i32 value) {
    // Not IMPLEMENTED
    return 0;
}

i32 list_max_i32(const List* self) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    i32 t = INT_MIN;
    for (u32 i = 0; i < self->length; i++) {
        i32 temp = *(i32*)list_get(self, i);
        if (temp > t) {
            t = temp;
        }
    }
    return t;
}

i32 list_min_i32(const List* self) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    i32 t = INT_MAX;
    for (u32 i = 0; i < self->length; i++) {
        i32 temp = *(i32*)list_get(self, i);
        if (temp < t) {
            t = temp;
        }
    }
    return t;
}

i32 list_get_i32(const List* self, u32 index) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    return *(i32*)list_get(self, index);
}

void list_set_i32(List* self, i32 data, u32 index) {
    if (self == NULL) {
        return;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return;
    }
    list_set(self, &data, index);
}

void reducer_sum_i32(void* result, const void* data, u32 elem_size) {
    *(i32*)result += *(i32*)data;
}
i32 list_sum_i32(const List* self) {
    if (self == NULL) {
        return 0;
    }
    if (self->t != I32) {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    i32 start = 0, reduced = 0;
    list_reduce(self, &start, &reduced, reducer_sum_i32);
    return reduced;
}