#pragma once

#include "defines.h"
#include "helper.h"
#include "strconv.h"

// List is a homogenous contiguous data structure.
// Capacity is dynamically adjusted by doubling or halving according to need.
typedef struct list
{
    void *arr;     // pointer to the underlying array
    u32 elem_size; // size of individual element
    DataType t;

    u32 length;   // length of the list
    u32 capacity; // capacity of the list
    b8 w_perm;    // write permission

    // in-built methods
    // Print handler for individual elements.
    void (*print_element)(const void *elem);
} List;

// Constructors
// Returns a new generic list of given element size.
List list_new(u32 capacity, u32 elem_size);
List list_new_i32(u32 capacity);
List list_new_f64(u32 capacity);

// Returns a copy from another list.
// The underlying array will be newly allocated.
List list_clone(const List *self);

// Creates a new list from existing list. The underlying array will be shared.
// Range -> [start,end]
// \param w_perm set the write permission.
List list_slice(const List *self, u32 start, u32 end, b8 w_perm);

// Creates a new list from existing list. The underlying array will be newly
// allocated.
// range -> [start,end)
List list_clone_slice(const List *self, u32 start, u32 end);

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append(List *self, void *data);
// Append an i32 to the list. Returns the updated length or -1 if error.
u32 list_append_i32(List *self, i32 data);
// Append an f64 to the list. Returns the updated length or -1 if error.
u32 list_append_f64(List *self, f64 data);

// Insert data into the list at the given index.
// \return the updated length or -1 if error.
u32 list_insert(List *self, void *data, u32 index);
u32 list_insert_i32(List *self, i32 data, u32 index);
u32 list_insert_f64(List *self, f64 data, u32 index);

// TODO: NOT IMPLEMENTED
// u32 list_bsearch_i32(const List* self, i32 value);
// u32 list_bsearch_f64(const List* self, f64 value);

// Deletes the data from the list at the given index.
// \return the updated length.
u32 list_delete(List *self, u32 index);

u32 list_search_i32(const List *self, i32 value);
u32 list_search_f64(const List *self, f64 value);

// Sets the printing function
void list_set_print_element(List *self, void (*handler)(const void *element));
//  Display the slice.
void list_display(const List *self);
// Display the slice with debug info.
void list_debug_display(const List *self);

// Getter
void *list_get(const List *self, u32 index);
i32 list_get_i32(const List *self, u32 index);
f64 list_get_f64(const List *self, u32 index);

// Setter
void list_set(List *self, void *data, u32 index);
void list_set_i32(List *self, i32 data, u32 index);
void list_set_f64(List *self, f64 data, u32 index);

void list_swap(List *self, i32 i, i32 j);

// \return the length of the list.
u32 list_len(const List *self);
// \return the capacity of the list.
u32 list_cap(const List *self);

// Frees the slice's underlying array.
// Only delete the original self i.e. the self containing the starting pointer.
void list_free(List *self);

// Updates the capacity when needed.
void update_list_cap(List *self, b8 can_shrink);

// Reduces the list to a single value according to the reducer.
// \param start initial value of accumulator.
// \param reduced container to put the reduced value.
// \param reducer function which receives the data pointer and the result pointer.
void list_reduce(const List *self, const void *start, void *reduced,
                 void (*reducer)(void *result, const void *data, u32 elem_size));

// Maps the elements of a list to another value according to the mapper.
// Modifies the list. So clone before mapping to preserve original.
void list_map(List *self, void (*mapper)(void *result, const void *data, u32 elem_size));

// Filters the list on the basis of the filterer, which provides a bool.
// Creates a new list.
List list_filter(const List *self, b8 (*filterer)(const void *data, u32 elem_size));

i32 list_sum_i32(const List *self);

f64 list_sum_f64(const List *self);
f64 list_mul_f64(const List *self);

i32 list_max_i32(const List *self);
i32 list_min_i32(const List *self);

f64 list_max_f64(const List *self);
f64 list_min_f64(const List *self);