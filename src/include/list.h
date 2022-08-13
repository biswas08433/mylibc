#pragma once

#include "defines.h"

typedef struct list
{
  // pointer to the underlying array
  void *arr;

  // size of individual element
  u32 elem_size;

  // length of the self
  u32 length;

  // capacity of the self befor reallocating
  u32 capacity;

  // write permission
  b8 w_perm;

  // Printing Function for the individual element.
  void (*print_func)(const void *elem);
} List;

// Returns a new generic list of given element size.
List list_new(u32 capacity, u32 elem_size);

// Returns a copy list from another list. The underlying array will be newly
// allocated.
List list_copy(const List *self);

// Creates a new list from existing list. The underlying array will be shared.
// \param w_perm set the write permission.
// Range -> [start,end)
List list_from(const List *self, u32 start, u32 end, b8 w_perm);

// Creates a new list from existing list. The underlying array will be newly
// allocated.
// range -> [start,end)
List list_new_from(const List *self, u32 start, u32 end);

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append(List *self, void *data);

// Insert data into the list at the given index.
// \return the updated length or -1 if error.
u32 list_insert(List *self, void *data, u32 index);

// Deletes the data from the list at the given index. Returns the updated
// length.
u32 list_delete(List *self, u32 index);

// Sets the printing function
void list_set_print_func(List *self, void (*print_func)(const void *elem));
//  Display the slice.
void list_display_dbg(const List *self);
// Display the slice with debug info.
void list_display(const List *self);

// Gets the element by the given index.
void *list_get(const List *self, u32 index);
// Sets the element by the given index.
void list_set(const List *self, u32 index, void *data);

// Returns the length of the slice.
u32 list_len(const List *self);
// Returns the capacity of the slice.
u32 list_cap(const List *self);

// Frees the slice's underlying array.
// Only delete the original self i.e. the self containing the starting pointer.
void list_free(List *self);

// Updates the capacity when needed.
// Returns FALSE if there is error in allocation. TRUE otherwise.
void update_list_cap(List *self, b8 can_shrink);