#pragma once

#include "defines.h"

typedef struct list_f64 {
  f64 *arr;      // pointer to the underlying array
  u32 length;    // length of the list
  u32 capacity;  // capacity of the list befor reallocating
  b8 w_perm;     // write permission
} List_f64;

// Returns a new list of f64.
List_f64 list_new_f64(u32 capacity);

// Returns a copy list from another self.
List_f64 list_copy_f64(List_f64 from);

// Creates a new list from existing list. The underlying array will be shared.
// w_perm set the write permission.
// range -> [start,end)
List_f64 list_from_f64(List_f64 *self, u32 start, u32 end, b8 w_perm);

// Creates a new list from existing self. The underlying array will be newly
// allocated.
// range -> [start,end)
List_f64 list_new_from_f64(List_f64 *self, u32 start, u32 end);

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_f64(List_f64 *self, f64 data);

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_f64(List_f64 *self, f64 data, u32 index);

// Deletes the data at given index. Returns the updated length.
u32 list_delete_f64(List_f64 *self, u32 index);

// Searches for the data. Returns -1 if not found.
u32 list_search_f64(List_f64 *self, f64 value);

// TODO: NOT IMPLEMENTED
u32 list_bsearch_f64(List_f64 *self, f64 value);

// Returns the maximum element from the self.
f64 list_max_f64(List_f64 *self);
// Returns the minimum element from the self.
f64 list_min_f64(List_f64 *self);

// Display the list.
void list_display_f64(List_f64 *self);
// Display the list with debug info.
void list_display_dbg_f64(List_f64 *self);

// Gets the element by the given index.
f64 list_get_f64(List_f64 *self, u32 index);
// Sets the element by the given index.
void list_set_f64(List_f64 *self, f64 value, u32 index);

// \return the length of the list.
u32 list_len_f64(List_f64 *self);
// \return the capacity of the list.
u32 list_cap_f64(List_f64 *self);

// Frees the self's underlying array.
// Only delete the original list i.e. the list containing the starting pof64er.
void list_free_f64(List_f64 *self);

// Updates the capacity when needed.
// \return FALSE if there is error in allocation. TRUE otherwise.
b8 list_update_cap_f64(List_f64 *self, b8 can_shrink);