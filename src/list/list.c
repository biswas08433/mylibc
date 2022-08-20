#include "../include/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/strconv.h"

List list_new(u32 capacity, u32 elem_size) {
    List temp;
    temp.arr = calloc(capacity, elem_size);
    if (temp.arr == NULL) {
        fprintf(stderr, "Allocation failed. Free up some memory.\n");
        exit(EXIT_FAILURE);
    }

    temp.elem_size = elem_size;
    temp.length = 0;
    temp.capacity = capacity;
    temp.w_perm = TRUE;
    temp.print_func = NULL;

    return temp;
}

List list_copy(const List* self) {
    List temp = list_new(self->capacity, self->elem_size);
    temp.elem_size = self->elem_size;
    temp.length = self->length;
    temp.capacity = self->capacity;
    temp.w_perm = TRUE;
    temp.print_func = self->print_func;

    // check if self is invalid
    if (self->arr == NULL) {
        fprintf(stderr, "Given list was empty\n");
        return temp;
    }
    memcpy(temp.arr, self->arr, self->length * temp.elem_size);

    return temp;
}

List list_from(const List* self, u32 start, u32 end, b8 w_perm) {
    List temp;
    temp.length = end - start;
    temp.capacity = w_perm ? self->capacity - start : 0;
    temp.w_perm = w_perm;
    // pointer arithmatic
    temp.arr = self->arr + start * (self->elem_size);
    temp.print_func = self->print_func;

    // check if self is invalid
    if (self->arr == NULL) {
        fprintf(stderr, "Given list was empty\n");
        return temp;
    }

    return temp;
}

List list_new_from(const List* self, u32 start, u32 end) {
    List temp;
    temp.length = end - start;
    temp.capacity = temp.length * 2;
    temp.w_perm = TRUE;
    temp.arr = calloc(temp.capacity, self->elem_size);
    temp.print_func = self->print_func;

    if (temp.arr == NULL) {
        fprintf(stderr, "Allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    // check if self is invalid
    if (self->arr == NULL) {
        fprintf(stderr, "Given list was empty.\n");
        return temp;
    }
    memcpy(temp.arr, self->arr + (start * self->elem_size), temp.length * self->elem_size);
    return temp;
}

u32 list_append(List* self, void* data) {
    update_list_cap(self, FALSE);
    if (self == NULL || data == NULL) {
        fprintf(stderr, "append data cannot be null.\n");
        return self->length;
    }
    if (self->w_perm == TRUE) {
        memcpy(self->arr + (self->length * self->elem_size), data, self->elem_size);
        self->length += 1;
        return self->length;
    } else {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

u32 list_insert(List* self, void* data, u32 index) {
    update_list_cap(self, FALSE);
    if (self == NULL || data == NULL) {
        fprintf(stderr, "data cannot be null.");
        exit(EXIT_FAILURE);
    }

    if (self->w_perm == TRUE) {
        // shift every right side element to the right one step
        for (u32 i = self->length - 1; i > index; i -= 1) {
            memcpy(self->arr + ((i + 1) * self->elem_size), self->arr + (i * self->elem_size), self->elem_size);
        }
        // insert
        memcpy(self->arr + (index * self->elem_size), data, self->elem_size);
        self->length += 1;
        return self->length;
    } else {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

u32 list_delete(List* self, u32 index) {
    if (self->w_perm == TRUE) {
        // shift every right side element to the left one step
        for (u32 i = index; i < self->length + 1; i += 1) {
            memcpy(self->arr + (i * self->elem_size), self->arr + ((i + 1) * self->elem_size), self->elem_size);
        }
        self->length -= 1;
        update_list_cap(self, TRUE);
        return self->length;
    } else {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

void list_set_print_func(List* self, void (*print_func)(void* elem)) {
    self->print_func = print_func;
}

void list_display(const List* self) {
    if (self->print_func == NULL) {
        fprintf(stderr, "No printing function found, provide one.\n");
        return;
    }
    printf("[");
    for (size_t i = 0; i < self->length; i++) {
        self->print_func(self->arr + (i * self->elem_size));
        if (i != self->length - 1) printf(",");
    }
    printf("]\n");
}

void list_display_dbg(const List* self) {
    if (self->print_func == NULL) {
        fprintf(stderr, "No printing function found, provide one.\n");
        return;
    }
    printf("{data: %p, elem_size: %d, len: %d, cap: %d, wperm: %s [", self->arr, self->elem_size, self->length,
           self->capacity, bool_str(self->w_perm));
    for (size_t i = 0; i < self->length; i++) {
        self->print_func(self->arr + (i * self->elem_size));
        if (i != self->length - 1) printf(",");
    }
    printf("] }\n");
}

void* list_get(const List* self, u32 index) {
    if (self->arr == NULL) {
        return NULL;
    }
    // check if index is out of bound
    if (index >= self->length || index < 0) {
        return NULL;
    }

    return self->arr + (index * self->elem_size);
}

void list_set(List* self, void* data, u32 index) {
    if (self->arr == NULL) {
        return;
    }
    if (index >= self->length || index < 0 || self->w_perm == FALSE) {
        fprintf(stderr, "invalid access");
        return;
    }
    memcpy(list_get(self, index), data, self->elem_size);
}

u32 list_len(const List* self) {
    return self->length;
}
u32 list_cap(const List* self) {
    return self->capacity;
}

void list_free(List* self) {
    if (self->w_perm == TRUE && self->arr != NULL) {
        free(self->arr);
        self->arr = NULL;
    }
}

void update_list_cap(List* self, b8 can_shrink) {
    if (self->length == self->capacity && self->w_perm == TRUE) {
        self->capacity *= 2;
        self->arr = realloc(self->arr, self->capacity * self->elem_size);
        if (self->arr == NULL) {
            fprintf(stderr, "capacity increase: memory allocation failed");
            exit(EXIT_FAILURE);
        }
    } else if (self->length < (self->capacity / 2) && self->w_perm == TRUE && can_shrink) {
        self->capacity /= 2;
        self->arr = realloc(self->arr, self->capacity * self->elem_size);
        if (self->arr == NULL) {
            fprintf(stderr, "capacity decrease: memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }
}