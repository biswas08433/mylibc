#pragma once

#include "defines.h"

// List is a homogenous contiguous data structure.
// Capacity is dynamically adjusted by doubling or halving according to length.
//
typedef struct list {
    void* arr;      // pointer to the underlying array
    u32 elem_size;  // size of individual element
    u32 length;     // length of the self
    u32 capacity;   // capacity of the self befor reallocating
    b8 w_perm;      // write permission

    // in-built methods
    // Printing Function for the individual element.
    void (*print_func)(void* elem);
} List;

// Returns a new generic list of given element size.
List list_new(u32 capacity, u32 elem_size);
List list_new_i32(u32 capacity);
List list_new_f64(u32 capacity);

// Returns a copy from another list.
// The underlying array will be newly allocated.
List list_copy(const List* self);

// Creates a new list from existing list. The underlying array will be shared.
// Range -> [start,end)
// \param w_perm set the write permission.
List list_from(const List* self, u32 start, u32 end, b8 w_perm);

// Creates a new list from existing list. The underlying array will be newly
// allocated.
// range -> [start,end)
List list_new_from(const List* self, u32 start, u32 end);

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append(List* self, void* data);
u32 list_append_i32(List* self, i32 data);
u32 list_append_f64(List* self, f64 data);

// Insert data into the list at the given index.
// \return the updated length or -1 if error.
u32 list_insert(List* self, void* data, u32 index);
u32 list_insert_i32(List* self, i32 data, u32 index);
u32 list_insert_f64(List* self, f64 data, u32 index);

// TODO: NOT IMPLEMENTED
u32 list_bsearch_i32(List* self, i32 value);
u32 list_bsearch_f64(List* self, f64 value);

// Deletes the data from the list at the given index.
// \return the updated length.
u32 list_delete(List* self, u32 index);

u32 list_search_i32(List* self, i32 value);
u32 list_search_f64(List* self, f64 value);

// Sets the printing function
void list_set_print_func(List* self, void (*print_func)(void* elem));
//  Display the slice.
void list_display(const List* self);
// Display the slice with debug info.
void list_display_dbg(const List* self);

void* list_get(const List* self, u32 index);
i32 list_get_i32(List* self, u32 index);
f64 list_get_f64(List* self, u32 index);

void list_set(List* self, void* data, u32 index);
void list_set_i32(List* self, i32 data, u32 index);
void list_set_f64(List* self, f64 data, u32 index);

// \return the length of the list.
u32 list_len(const List* self);
// \return the capacity of the list.
u32 list_cap(const List* self);

// Frees the slice's underlying array.
// Only delete the original self i.e. the self containing the starting pointer.
void list_free(List* self);

// Updates the capacity when needed.
void update_list_cap(List* self, b8 can_shrink);

i32 list_max_i32(List* self);
i32 list_min_i32(List* self);
f64 list_max_f64(List* self);
f64 list_min_f64(List* self);