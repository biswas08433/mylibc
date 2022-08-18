#pragma once

#include "defines.h"
#include "llist.h"

typedef struct stack {
    LList arr;
    i32 top;
} Stack;

Stack stack_new(u32 capacity);

// Pushes an element to the stack.
// \return updated top.
u32 push(Stack* self, Object src);

// Pops the top of the stack.
// Assumes the object provided have preallocated memory.
// Either in stack or heap.
// \return updated top.
u32 pop(Stack* self, Object dst);
// Peeks at the top of the stack
Object peek(Stack* self);
// Drains the stack.
void drain(Stack* self);

b8 stack_is_empty(Stack* self);
b8 stack_is_full(Stack* self);
u32 stack_size(Stack* self);

void stack_display(Stack* self);
void stack_display_dbg(Stack* self);
void stack_print_handler(Stack* self, void (*handler)(void* data));

void stack_free(Stack* self);
