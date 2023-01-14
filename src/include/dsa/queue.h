#pragma once

#include "defines.h"
#include "llist.h"

typedef struct queue {
    LList arr;
} Queue;

Queue queue_new(u32 capacity);

// Pushes an element to the queue.
// \return updated top.
u32 enq(Queue* self, Object src);

// Pops the top of the queue.
// Assumes the object provided have preallocated memory.
// Either in queue or heap.
// \return updated top.
u32 deq(Queue* self, Object dst);
// Peeks at the top of the queue
Object q_peek(Queue* self);
// Drains the queue.
void q_drain(Queue* self);

b8 queue_is_empty(Queue* self);
b8 queue_is_full(Queue* self);
u32 queue_size(Queue* self);

void queue_display(Queue* self);
void queue_display_dbg(Queue* self);
void queue_print_handler(Queue* self, void (*handler)(void* data));

void queue_free(Queue* self);
