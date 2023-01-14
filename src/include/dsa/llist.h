#pragma once

#include "defines.h"
#include "mystring.h"

// Node Struct
typedef struct lnode {
    Object core;
    struct lnode* next;  // pointer to the next node
    // Internal Methods
    void (*print_node)(const void* data);  // Node printing handler

} LNode;

//// LList is a heterogenous linear data structure.
// Linked List struct, contains metadata
typedef struct llist {
    LNode* head;  // ptr to the first node
    LNode* tail;  // ptr to the last node
    LNode* ctx;   // Similar to selecting. By default, last entered node.
    u32 len;
    // Internal Methods
    void (*print_node_default)(const void* data);  // Node printing handler
} LList;

LNode* lnode_new(Object src);
void lnode_set(LNode* self, Object src);
void lnode_free(LNode* self);
// TODO: Optimize by tail.
//  Gives back the pointer to the node specified by index.
//  NULL if not found.
LNode* llist_getnode(const LList* self, u32 index);

// Returns an empty LList
LList llist_new();

// Appends an node to the end of the llist.
// \return Updated length. -1 if any error.
u32 llist_append(LList* self, Object src);
u32 llist_append_i32(LList* self, i32 data);
u32 llist_append_f64(LList* self, f64 data);
u32 llist_append_b8(LList* self, b8 data);
u32 llist_append_str(LList* self, String data);

// Prepends an node to the start of the llist.
// \return Updated length. -1 if any error.
u32 llist_prepend(LList* self, Object src);

// Inserts an element at the given index.
u32 llist_insert(LList* self, u32 index, Object src);

u32 llist_delete(LList* self, u32 index);

Object llist_get(const LList* self, u32 index);
void llist_set(LList* self, u32 index, Object src);

// Returns index if found. -1 otherwise.
// \param data_src pointer to the external data to compare.
// \param compare returns 0 if equal, 1 if data > data_src, -1 otherwise.
u32 llist_search(const LList* self, Object src, i32 (*compare)(const void* data, const void* data_src));

void llist_display(const LList* self);
void llist_display_dbg(const LList* self);
void llist_display_till(const LList* self, u32 index);
void lnode_ctx_print_func(LList* self, void (*handler)(const void* data));
void llist_default_print_func(LList* self, void (*handler)(const void* data));

// Delete the LList
void llist_free(LList* self);
