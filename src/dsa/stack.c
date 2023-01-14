#include "dsa/stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack stack_new(u32 capacity) {
    Stack temp;
    temp.arr = llist_new(capacity);
    temp.top = -1;
    return temp;
}

u32 push(Stack* self, Object src) {
    self->top += 1;
    LNode* temp = llist_getnode(&self->arr, self->top);
    if (temp != NULL) {
        lnode_set(temp, src);
    } else {
        llist_append(&self->arr, src);
    }
    return self->top;
}

u32 pop(Stack* self, Object dst) {
    if (stack_is_empty(self) != TRUE) {
        Object popped = llist_get(&self->arr, self->top);
        if (dst.size == popped.size) {
            memcpy(dst.data, popped.data, popped.size);
        }
        self->top -= 1;
    }
    return self->top;
}

Object peek(Stack* self) {
    if (stack_is_empty(self) != TRUE) {
        Object peeked = llist_get(&self->arr, self->top);
        return peeked;
    }
    return (Object){NULL, 0};
}
// Drains the stack.
void drain(Stack* self) {
    self->top = -1;
}

b8 stack_is_empty(Stack* self) {
    return self->top == -1;
}
b8 stack_is_full(Stack* self) {
    return FALSE;
}
u32 stack_size(Stack* self) {
    return self->top + 1;
}

void stack_display(Stack* self) {
    if (stack_is_empty(self) == TRUE) {
        printf("stack[]\n");
    } else {
        printf("stack");
        llist_display_till(&self->arr, self->top);
    }
}
void stack_display_dbg(Stack* self) {
    printf("stack(top: %d)", self->top);
    llist_display_dbg(&self->arr);
}

<<<<<<< HEAD:src/dsa/stack.c
void stack_print_handler(Stack* self, void (*handler)(void* data)) {
=======
void stack_print_handler(Stack* self, void (*handler)(const void* data)) {
>>>>>>> e94f3299efdaab3487acf84208fd67976f1febba:src/stack/stack.c
    llist_default_print_func(&self->arr, handler);
}

void stack_free(Stack* self) {
    llist_free(&self->arr);
    self->top = -1;
}