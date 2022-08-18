#pragma once

#include "defines.h"

// Node Struct
typedef struct lnode {
    Object core;
    struct lnode* next;  // pointer to the next node
    // Internal Methods
    void (*print_node)(void* data);  // Node printing handler

} LNode;

// Linked List struct, contains metadata
typedef struct llist {
    LNode* head;
    LNode* tail;
    LNode* ctx;  // Similar to selecting. By default, last entered node.
    u32 len;
    // Internal Methods
    void (*print_node_default)(void* data);  // Node printing handler
} LList;

LNode* lnode_new(Object src);
void lnode_set(LNode* self, Object src);
void lnode_free(LNode* self);
// TODO: Optimize by tail.
//  Gives back the pointer to the node specified by index.
//  NULL if not found.
LNode* llist_getnode(LList* self, u32 index);

// Returns an empty LList
LList llist_new();

// Appends an node to the end of the llist.
// \return Updated length. -1 if any error.
u32 llist_append(LList* self, Object src);

// Prepends an node to the start of the llist.
// \return Updated length. -1 if any error.
u32 llist_prepend(LList* self, Object src);

// Inserts an element at the given index.
u32 llist_insert(LList* self, u32 index, Object src);

u32 llist_delete(LList* self, u32 index);

Object llist_get(LList* self, u32 index);
void llist_set(LList* self, u32 index, Object src);

// Returns index if found. -1 otherwise.
// \param data_src pointer to the external data to compare.
// \param compare returns 0 if equal, 1 if data > data_src, -1 otherwise.
u32 llist_search(LList* self, Object src, i32 (*compare)(void* data, void* data_src));

void llist_display(const LList* self);
void llist_display_dbg(const LList* self);
void llist_display_till(const LList* self, u32 index);
void lnode_print_func(LList* self, void (*handler)(void* data));
void llist_default_print_func(LList* self, void (*handler)(void* data));

// Delete the LList
void llist_free(LList* self);
