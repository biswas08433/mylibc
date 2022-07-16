#pragma once

#include "defines.h"

// Node Struct
typedef struct lnode_f64
{
    f64 data;
    struct lnode_f64 *next;
} LNode_f64;

// Linked List struct, contains metadata
typedef struct llist_f64
{
    LNode_f64 *head;
    LNode_f64 *tail;
    u32 len;
} LList_f64;

// Returns an empty LList(f64)
LList_f64 llist_new_f64();

// Appends an node to the end of the llist.
// \return Updated length. -1 if any error.
u32 llist_append_f64(LList_f64 *self, f64 value);

// Prepends an node to the start of the llist.
// \return Updated length. -1 if any error.
u32 llist_prepend_f64(LList_f64 *self, f64 value);

// void llist_insert_f64(i, v);
// void llist_delete_f64(i);
// void llist_get_f64(i);
// void llist_set_f64(i, v);

// void llist_search_f64(i, v);

void display_llist_f64(LList_f64 *self);
void display_debug_llist_f64(LList_f64 *self);

// Delete the LList
void llist_delete_f64(LList_f64 *self);
