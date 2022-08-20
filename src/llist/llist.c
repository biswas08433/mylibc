#include "../include/llist.h"
#include "../include/mystring.h"
#include "../include/helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LList llist_new() {
    LList temp;
    temp.head = NULL;
    temp.tail = NULL;
    temp.ctx = NULL;
    temp.len = 0;
    return temp;
}

// Internal function for newly allocated node.
LNode* lnode_new(Object src) {
    void* data = calloc(1, src.size);
    if (data == NULL) {
        fprintf(stderr, "Allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(data, src.data, src.size);

    LNode* temp = (LNode*)calloc(1, sizeof(LNode));

    if (temp == NULL) {
        fprintf(stderr, "Allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    temp->core.data = data;
    temp->core.size = src.size;
    temp->core.t = src.t;

    temp->next = NULL;
    temp->print_node = NULL;

    return temp;
}

void lnode_set(LNode* self, Object src) {
    if (self != NULL) {
        if (self->core.size != src.size) {
            self->core.data = realloc(self->core.data, src.size);
        }
        memcpy(self->core.data, src.data, src.size);
        self->core.size = src.size;
    }
}

// Internal function for deleting and freeing a node.
void lnode_free(LNode* self) {
    if (self != NULL) {
        if (self->core.data != NULL) {
            free(self->core.data);
        }
        free(self);
        self = NULL;
    }
}

LNode* llist_getnode(LList* self, u32 index) {
    if (self->head == NULL) {
        return NULL;
    }
    if (index >= self->len || index < 0) {
        return NULL;
    }
    LNode* iter = self->head;
    for (u32 i = 0; i < index; i++) {
        iter = iter->next;
    }
    return iter;
}

u32 llist_append(LList* self, Object src) {
    LNode* temp = lnode_new(src);

    // Exit if allocation failed
    if (temp == NULL) {
        exit(EXIT_FAILURE);
    }

    // if list is uninitialized
    if (self->head == NULL) {
        self->head = temp;
        self->tail = temp;
    } else {
        self->tail->next = temp;
        self->tail = temp;
    }
    self->ctx = temp;
    self->len += 1;
    return self->len;
}

u32 llist_append_i32(LList* self, i32 data) {
    u32 len = llist_append(self, (Object){&data, sizeof(i32), I32});
    lnode_ctx_print_func(self, print_i32);
    return len;
}
u32 llist_append_f64(LList* self, f64 data) {
    u32 len = llist_append(self, (Object){&data, sizeof(f64), F64});
    lnode_ctx_print_func(self, print_f64);
    return len;
}
u32 llist_append_b8(LList* self, b8 data) {
    u32 len = llist_append(self, (Object){&data, sizeof(b8), B8});
    lnode_ctx_print_func(self, print_b8);
    return len;
}
u32 llist_append_str(LList* self, String s) {
    u32 len = llist_append(self, (Object){&(s.data), sizeof(String), STRING});
    lnode_ctx_print_func(self, print_string);
    return len;
}

u32 llist_prepend(LList* self, Object src) {
    LNode* temp = lnode_new(src);

    // Exit if allocation failed
    if (temp == NULL) {
        exit(EXIT_FAILURE);
    }
    // if list is uninitialized
    if (self->head == NULL) {
        self->head = temp;
        self->tail = temp;
    } else {
        temp->next = self->head;
        self->head = temp;
    }
    self->ctx = temp;
    self->len += 1;
    return self->len;
}

u32 llist_insert(LList* self, u32 index, Object src) {
    if (index >= self->len || index < 0) {
        return self->len;
    } else if (index == 0) {
        return llist_prepend(self, src);
    } else {
        LNode* temp = lnode_new(src);
        // Exit if allocation failed
        if (temp == NULL) {
            exit(EXIT_FAILURE);
        }

        // if list is uninitialized
        if (self->head == NULL) {
            self->head = temp;
            self->tail = temp;
            // TODO log that the given index is not valid as list is uninitialized
            self->len += 1;
            return self->len;
        }
        LNode* prev = llist_getnode(self, index - 1);
        temp->next = prev->next;
        prev->next = temp;
        self->ctx = temp;
        self->len += 1;
    }
    return self->len;
}

u32 llist_delete(LList* self, u32 index) {
    if (index >= self->len || index < 0) {
        return self->len;
    } else if (index == 0) {
        LNode* temp = self->head;
        self->head = temp->next;
        lnode_free(temp);
        return self->len;
    } else {
        LNode* prev = llist_getnode(self, index - 1);
        LNode* del = prev->next;
        prev->next = del->next;
        lnode_free(del);
        self->ctx = NULL;
        self->len -= 1;
        return self->len;
    }
}

Object llist_get(LList* self, u32 index) {
    LNode* temp = llist_getnode(self, index);
    return (Object){temp->core.data, temp->core.size, temp->core.t};
}

void llist_set(LList* self, u32 index, Object src) {
    LNode* prev = llist_getnode(self, index - 1);
    LNode* dst = prev->next;
    if (prev == NULL || dst == NULL) {
        return;
    }
    if (dst->core.size != src.size) {
        LNode* temp = dst->next;
        free(dst);
        dst = lnode_new(src);
        prev->next = dst;
        dst->next = temp;
        return;
    }
    memcpy(dst->core.data, src.data, src.size);
}

u32 llist_search(LList* self, Object src, i32 (*compare)(void* data, void* data_src)) {
    if (self->head == NULL) {
        printf("llist empty");
        return -1;
    }
    u32 i = 0;
    for (LNode* iter = self->head; iter != NULL; iter = iter->next) {
        if (compare(iter->core.data, src.data) == 0) {
            self->ctx = iter;
            return i;
        }
        i += 1;
    }
    return -1;
}

void llist_free(LList* self) {
    if (self->head != NULL) {
        LNode* temp2 = self->head;
        for (LNode* temp1 = self->head; temp1 != NULL; temp1 = temp2) {
            temp2 = temp2->next;
            lnode_free(temp1);
        }
        self->head = NULL;
        self->tail = NULL;
        self->ctx = NULL;
        self->len = 0;
    }
}

// -------------------------------------------PRINTING UTILITY------------------------------------------

void llist_display(const LList* self) {
    printf("[");
    if (self->head != NULL) {
        for (LNode* iter = self->head; iter != NULL; iter = iter->next) {
            if (iter->print_node != NULL) {
                iter->print_node(iter->core.data);
            } else if (self->print_node_default != NULL) {
                self->print_node_default(iter->core.data);
            } else {
                printf("no printing funtion found\n");
                return;
            }
            if (iter->next != NULL) {
                printf(" ");
            }
        }
    }
    printf("]\n");
}
void llist_display_dbg(const LList* self) {
    printf("{head: %p, tail: %p, len: %d, [", self->head, self->tail, self->len);
    if (self->head != NULL) {
        u32 i = 0;
        for (LNode* iter = self->head; iter != NULL; iter = iter->next) {
            printf("(%d): ", i);
            // Checking if node-specific printing func exist.
            if (iter->print_node != NULL) {
                iter->print_node(iter->core.data);
            } else if (self->print_node_default != NULL) {
                // if no node-specific found, then trying default
                self->print_node_default(iter->core.data);
            } else {
                printf("no printing funtion found\n");
                return;
            }
            if (iter->next != NULL) {
                printf(" -> ");
            }
            i += 1;
        }
    }
    printf("] }\n");
}
void llist_display_till(const LList* self, u32 index) {
    printf("[");
    if (self->head != NULL) {
        u32 i = 0;
        for (LNode* iter = self->head; iter != NULL; iter = iter->next) {
            if (iter->print_node != NULL) {
                iter->print_node(iter->core.data);
            } else if (self->print_node_default != NULL) {
                self->print_node_default(iter->core.data);
            } else {
                printf("no printing func found\n");
                return;
            }
            if (iter->next != NULL) {
                printf(" ");
            }
            // break if index is reached
            if (i == index) {
                break;
            }
            i += 1;
        }
    }
    printf("]\n");
}

void lnode_ctx_print_func(LList* self, void (*handler)(void* data)) {
    if (self->head != NULL && self->ctx != NULL) {
        self->ctx->print_node = handler;
    }
}
void llist_default_print_func(LList* self, void (*handler)(void* data)) {
    self->print_node_default = handler;
}