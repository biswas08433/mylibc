#pragma once

#include "defines.h"

typedef struct slice_i32
{
    i32 *arr;     // poi32er to the underlying array
    u32 length;   // length of the self
    u32 capacity; // capacity of the self befor reallocating
    b8 w_perm;    // write permission
} Slice_i32;

// Returns a new self of i32.
Slice_i32 slice_new_i32(u32 capacity);

// Returns a copy self from another self.
Slice_i32 slice_copy_i32(Slice_i32 from);

// Creates a new self from existing self. The underlying array will be shared.
// w_perm set the write permission.
// range -> [start,end)
Slice_i32 slice_from_i32(Slice_i32 *self, u32 start, u32 end, b8 w_perm);

// Creates a new self from existing self. The underlying array will be newly allocated.
// range -> [start,end)
Slice_i32 slice_new_from_i32(Slice_i32 *self, u32 start, u32 end);

// Append an element to the self. Returns the updated length or -1 if error.
u32 append_i32(Slice_i32 *self, i32 data);

// Insert data i32o given index. Returns the updated length or -1 if error.
u32 insert_i32(Slice_i32 *self, i32 data, u32 index);

// Deletes the data at given index. Returns the updated length.
u32 delete_i32(Slice_i32 *self, u32 index);

// Searches for the data. Returns -1 if not found.
u32 search_i32(Slice_i32 *self, i32 value);

u32 bsearch_i32(Slice_i32 *self, i32 value); // NOT IMPLEMENTED

// Returns the maximum element from the self.
i32 max_slice_i32(Slice_i32 *self);
// Returns the minimum element from the self.
i32 min_slice_i32(Slice_i32 *self);

// Display the self.
void display_debug_i32(Slice_i32 *self);
// Display the self with debug info.
void display_i32(Slice_i32 *self);

// Gets the element by the given index.
i32 get_i32(Slice_i32 *self, u32 index);
// Sets the element by the given index.
void set_i32(Slice_i32 *self, i32 value, u32 index);

// Returns the length of the self.
u32 len_i32(Slice_i32 *self);
// Returns the capacity of the self.
u32 cap_i32(Slice_i32 *self);

// Frees the self's underlying array.
// Only delete the original self i.e. the self containing the starting poi32er.
void slice_delete_i32(Slice_i32 *self);

// Updates the capacity when needed.
// Returns FALSE if there is error in allocation. TRUE otherwise.
b8 update_cap_i32(Slice_i32 *self, b8 can_shrink);