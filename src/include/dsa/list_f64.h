#pragma once

#include "defines.h"
#include "list.h"

// Returns a new list of f64.
List list_new_f64(u32 capacity);
// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_f64(List* self, f64 data);

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_f64(List* self, f64 data, u32 index);

// Searches for the data. Returns -1 if not found.
u32 list_search_f64(List* self, f64 value);

// TODO: NOT IMPLEMENTED
u32 list_bsearch_f64(List* self, f64 value);

// Returns the maximum element from the self.
f64 list_max_f64(List* self);
// Returns the minimum element from the self.
f64 list_min_f64(List* self);

// Gets the element by the given index.
f64 list_get_f64(List* self, u32 index);
// Sets the element by the given index.
void list_set_f64(List* self, f64 data, u32 index);