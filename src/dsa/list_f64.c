#include "dsa/list.h"
#include "helper.h"
#include "strconv.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

List list_new_f64(u32 capacity)
{
    List temp = list_new(capacity, sizeof(f64));
    temp.t = F64;
    list_set_print_element(&temp, print_f64);
    return temp;
}

// Append an element to the list. Returns the updated length or -1 if error.
u32 list_append_f64(List *self, f64 data)
{
    return list_append(self, &data);
}

// Insert data into given index. Returns the updated length or -1 if error.
u32 list_insert_f64(List *self, f64 data, u32 index)
{
    return list_insert(self, &data, index);
}

// Searches for the data. Returns -1 if not found.
u32 list_search_f64(const List *self, f64 value)
{
    for (u32 i = 0; i < self->length; i++)
    {
        f64 temp = list_get_f64(self, i);
        if (fabs(temp - value) <= DBL_EPSILON)
        {
            return i;
        }
    }
    return -1;
}

// TODO: NOT IMPLEMENTED
u32 list_bsearch_f64(const List *self, f64 value)
{
    // NOT IMPLEMENTED
    return 0;
}

// Returns the maximum element from the self.
f64 list_max_f64(const List *self)
{
    f64 t = DBL_MIN;
    for (u32 i = 0; i < self->length; i++)
    {
        f64 temp = list_get_f64(self, i);
        if (temp - t > DBL_EPSILON)
        {
            t = temp;
        }
    }
    return t;
}
// Returns the minimum element from the self.
f64 list_min_f64(const List *self)
{
    f64 t = DBL_MAX;
    for (u32 i = 0; i < self->length; i++)
    {
        f64 temp = list_get_f64(self, i);
        if (temp - t < DBL_EPSILON)
        {
            t = temp;
        }
    }
    return t;
}

// Gets the element by the given index.
f64 list_get_f64(const List *self, u32 index)
{
    return *(f64 *)list_get(self, index);
}
// Sets the element by the given index.
void list_set_f64(List *self, f64 data, u32 index)
{
    list_set(self, &data, index);
}

void reducer_sum_f64(void *result, const void *data, u32 elem_size)
{
    *(f64 *)result += *(f64 *)data;
}
void reducer_mul_f64(void *result, const void *data, u32 elem_size)
{
    *(f64 *)result *= *(f64 *)data;
}
f64 list_sum_f64(const List *self)
{
    if (self == NULL)
    {
        return 0;
    }
    if (self->t != F64)
    {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    f64 start = 0, reduced = 0;
    list_reduce(self, &start, &reduced, reducer_sum_f64);
    return reduced;
}
f64 list_mul_f64(const List *self)
{
    if (self == NULL)
    {
        return 0;
    }
    if (self->t != F64)
    {
        fprintf(stderr, "list does not contain I32\n");
        return 0;
    }
    f64 start = 0, reduced = 0;
    list_reduce(self, &start, &reduced, reducer_mul_f64);
    return reduced;
}