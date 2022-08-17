#pragma once

#include "defines.h"
#include "list.h"

typedef struct stack {
  List arr;
  i32 top;
} Stack;

Stack stack_new(u32 capacity);

// Pushes an element to the stack
u32 push(Stack* self, Data data);
// Pops the top of the stack
u32 pop(Stack* self, Data data);
// Peeks at the top of the stack
void peek();
// Drains the stack.
void drain();

bool is_empty();
bool is_full();
u32 stack_size();
