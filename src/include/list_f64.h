#pragma once

#include "defines.h"

typedef struct slice_f64
{
    f64 *arr;     // pointer to the underlying array
    u32 length;   // length of the self
    u32 capacity; // capacity of the self before it reallocates
    b8 w_perm;    // write permission
} Slice_f64;

// Returns a new self of f64.
Slice_f64 slice_new_f64(u32 capacity);
Slice_f64 copy_slice_f64(Slice_f64 from);
Slice_f64 slice_from_f64(Slice_f64 *self, u32 start, u32 end, b8 w_perm);
Slice_f64 slice_new_from_f64(Slice_f64 *self, u32 start, u32 end);

u32 append_f64(Slice_f64 *self, f64 data);
u32 insert_f64(Slice_f64 *self, f64 data, u32 index);
u32 delete_f64(Slice_f64 *self, u32 index);

u32 search_f64(Slice_f64 *self, f64 value);
u32 bsearch_f64(Slice_f64 *self, f64 value); // NOT IMPLEMENTED

u32 slice_max_f64(Slice_f64 *self);
u32 slice_min_f64(Slice_f64 *self);

void display_debug_f64(Slice_f64 *self);
void display_f64(Slice_f64 *self);

f64 get_f64(Slice_f64 *self, u32 index);
void set_f64(Slice_f64 *self, f64 value, u32 index);

u32 len_f64(Slice_f64 *self);
u32 cap_f64(Slice_f64 *self);

void slice_free_f64(Slice_f64 *self);

u32 update_cap_f64(Slice_f64 *self, b8 can_shrink);