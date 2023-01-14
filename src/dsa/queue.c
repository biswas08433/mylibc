#include "dsa/queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue queue_new(u32 capacity) {
    Queue temp;
    temp.arr = llist_new(capacity);
    return temp;
}

u32 enq(Queue* self, Object src) {
    llist_append(&self->arr, src);
    return self->arr.len;
}

u32 deq(Queue* self, Object dst) {
    if (queue_is_empty(self) != TRUE) {
        LNode* temp = self->arr.head;
        if (dst.size == temp->core.size) {
            memcpy(dst.data, temp->core.data, temp->core.size);
        }
    }
    llist_delete(&self->arr, 0);
    return self->arr.len;
}

Object q_peek(Queue* self) {
    Object head = self->arr.head->core;
    return (Object){head.data, head.size};
}
// Drains the queue.
void q_drain(Queue* self) {
    llist_free(&self->arr);
}

b8 queue_is_empty(Queue* self) {
    return (self->arr.len == 0);
}
b8 queue_is_full(Queue* self) {
    return FALSE;
}
u32 queue_size(Queue* self) {
    return self->arr.len;
}

void queue_display(Queue* self) {
    if (queue_is_empty(self) == TRUE) {
        printf("queue[]\n");
    } else {
        printf("queue");
        llist_display(&self->arr);
    }
}
void queue_display_dbg(Queue* self) {
    printf("queue");
    llist_display_dbg(&self->arr);
}
void queue_print_handler(Queue* self, void (*handler)(void* data)) {
    llist_default_print_func(&self->arr, handler);
}

void queue_free(Queue* self) {
    llist_free(&self->arr);
}
