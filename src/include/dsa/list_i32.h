#pragma once

#include "defines.h"
#include "list.h"

// Returns a new list of i32.
List list_new_i32(u32 capacity);

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_i32(List* self, i32 data);

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_i32(List* self, i32 data, u32 index);

// Deletes the data at given index. Returns the updated length.
u32 list_delete_i32(List* self, u32 index);

// Searches for the data. Returns -1 if not found.
u32 list_search_i32(List* self, i32 value);

// TODO: NOT IMPLEMENTED
u32 list_bsearch_i32(List* self, i32 value);

// Returns the maximum element from the self.
i32 list_max_i32(List* self);
// Returns the minimum element from the self.
i32 list_min_i32(List* self);

// Gets the element by the given index.
i32 list_get_i32(List* self, u32 index);
// Sets the element by the given index.
void list_set_i32(List* self, i32 data, u32 index);