#include "../include/sort_i32.h"
#include "../include/helper.h"

#include <limits.h>

// Bubble Sort
void bub_sort_i32(Slice_i32 *self)
{
    i32 *arr = self->arr;
    u32 length = self->length;
    b8 swapped;
    for (u32 i = 0; i < length; i += 1)
    {
        swapped = FALSE;
        for (u32 j = 0; j < length - i - 1; j += 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_i32(&arr[j], &arr[j + 1]);
                swapped = TRUE;
            }
        }
        if (swapped == FALSE)
        {
            break;
        }
    }
}

// Selection Sort
void sel_sort_i32(Slice_i32 *self)
{
    if (is_sorted_i32(self) == TRUE)
    {
        return;
    }
    i32 *arr = self->arr;
    u32 length = self->length;
    i32 min_index;
    for (u32 i = 0; i < length; i++)
    {
        i32 min = INT_MAX;
        for (u32 j = i; j < length; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }
        if (arr[i] != arr[min_index])
        {
            swap_i32(&arr[i], &arr[min_index]);
        }
    }
}

// NOT IMPLEMENTED
void merge_sort_i32(Slice_i32 *self)
{
    // NOT IMPLEMENTED
}

// this return 2 if the self is not sorted; else returns the slope.
// -1 -> not descending order
// 0 -> same
// 1-> not ascending order
i32 order_i32(Slice_i32 *self)
{
    i32 *arr = self->arr;
    u32 length = self->length;

    if (length <= 1)
    {
        return 0;
    }
    i32 order = comp_i32(arr[0], arr[1]);
    for (u32 i = 1; i < length - 1; i++)
    {
        i32 new_order = comp_i32(arr[i], arr[i + 1]);
        if (order == 0 && new_order != 0)
        {
            order = new_order;
            continue;
        }
        if (new_order != 0 && new_order != order)
        {
            return 2;
        }
    }
    return order;
}

// Returns TRUE if sorted; FALSE otherwise.
b8 is_sorted_i32(Slice_i32 *self)
{
    if (order_i32(self) == 2)
    {
        return FALSE;
    }
    return TRUE;
}

// Merges two sorted slices and returns a new self.
Slice_i32 merge_i32(Slice_i32 *a, Slice_i32 *b)
{
    Slice_i32 r = slice_new_i32((a->length + b->length) * 2);

    i32 a_length = a->length;
    i32 b_length = b->length;
    i32 a_pointer = 0, b_pointer = 0;

    while (a_pointer < a_length && b_pointer < b_length)
    {
        if (a->arr[a_pointer] <= b->arr[b_pointer])
        {
            append_i32(&r, a->arr[a_pointer]);
            a_pointer += 1;
        }
        else
        {
            append_i32(&r, b->arr[b_pointer]);
            b_pointer += 1;
        }
    }
    for (int i = a_pointer; i < a_length; i++)
    {
        append_i32(&r, a->arr[i]);
    }
    for (int i = b_pointer; i < b_length; i++)
    {
        append_i32(&r, b->arr[i]);
    }
    return r;
}
