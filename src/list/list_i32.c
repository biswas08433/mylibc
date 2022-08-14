#include "../include/list_i32.h"
#include "../include/helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

List_i32 list_new_i32(u32 capacity) {
  List_i32 temp_slice;
  temp_slice.length = 0;
  temp_slice.capacity = capacity;
  temp_slice.w_perm = TRUE;
  temp_slice.arr = (i32 *)malloc(temp_slice.capacity * sizeof(i32));
  init_i32(temp_slice.arr, capacity, 0);

  return temp_slice;
}

List_i32 list_copy_i32(List_i32 from) {
  List_i32 temp_slice = list_new_i32(from.capacity);
  temp_slice.length = from.length;
  copy_i32(from.arr, temp_slice.arr, from.length);
  return temp_slice;
}

List_i32 list_from_i32(List_i32 *self, u32 start, u32 end, b8 w_perm) {
  List_i32 new_slice;
  new_slice.length = end - start;
  new_slice.capacity = w_perm ? self->capacity - start : 0;
  new_slice.w_perm = w_perm;
  new_slice.arr = self->arr + start;

  return new_slice;
}

List_i32 list_new_from_i32(List_i32 *self, u32 start, u32 end);

u32 append_i32(List_i32 *self, i32 data);

u32 insert_i32(List_i32 *self, i32 data, u32 index);

u32 delete_i32(List_i32 *self, u32 index);

u32 search_i32(List_i32 *self, i32 value);

u32 bsearch_i32(List_i32 *self, i32 value);

i32 max_list_i32(List_i32 *self);

i32 min_list_i32(List_i32 *self);

void display_debug_i32(List_i32 *self);

void display_i32(List_i32 *self);

i32 get_i32(List_i32 *self, u32 index);

void set_i32(List_i32 *self, i32 value, u32 index);

// Returns the length of the self.
u32 len_i32(List_i32 *self);
// Returns the capacity of the self.
u32 cap_i32(List_i32 *self);

// Frees the self's underlying array.
// Only delete the original self i.e. the self containing the starting poi32er.
void list_free_i32(List_i32 *self);

// Updates the capacity when needed.
// Returns FALSE if there is error in allocation. TRUE otherwise.
b8 update_cap_i32(List_i32 *self, b8 can_shrink);