#pragma once

#include "defines.h"

typedef struct list_i32 {
  i32 *arr;      // pointer to the underlying array
  u32 length;    // length of the list
  u32 capacity;  // capacity of the list befor reallocating
  b8 w_perm;     // write permission
} List_i32;

// Returns a new list of i32.
List_i32 list_new_i32(u32 capacity);

// Returns a copy list from another self.
List_i32 list_copy_i32(List_i32 from);

// Creates a new list from existing list. The underlying array will be shared.
// w_perm set the write permission.
// range -> [start,end)
List_i32 list_from_i32(List_i32 *self, u32 start, u32 end, b8 w_perm);

// Creates a new list from existing self. The underlying array will be newly
// allocated.
// range -> [start,end)
List_i32 list_new_from_i32(List_i32 *self, u32 start, u32 end);

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_i32(List_i32 *self, i32 data);

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_i32(List_i32 *self, i32 data, u32 index);

// Deletes the data at given index. Returns the updated length.
u32 list_delete_i32(List_i32 *self, u32 index);

// Searches for the data. Returns -1 if not found.
u32 list_search_i32(List_i32 *self, i32 value);

// TODO: NOT IMPLEMENTED
u32 list_bsearch_i32(List_i32 *self, i32 value);

// Returns the maximum element from the self.
i32 list_max_i32(List_i32 *self);
// Returns the minimum element from the self.
i32 list_min_i32(List_i32 *self);

// Display the list.
void list_display_i32(List_i32 *self);
// Display the list with debug info.
void list_display_dbg_i32(List_i32 *self);

// Gets the element by the given index.
i32 list_get_i32(List_i32 *self, u32 index);
// Sets the element by the given index.
void list_set_i32(List_i32 *self, i32 value, u32 index);

// \return the length of the list.
u32 list_len_i32(List_i32 *self);
// \return the capacity of the list.
u32 list_cap_i32(List_i32 *self);

// Frees the self's underlying array.
// Only delete the original list i.e. the list containing the starting poi32er.
void list_free_i32(List_i32 *self);

// Updates the capacity when needed.
// \return FALSE if there is error in allocation. TRUE otherwise.
b8 list_update_cap_i32(List_i32 *self, b8 can_shrink);