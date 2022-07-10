#include "../include/sort_int.h"

// Bubble Sort
void bub_sort_int(SliceInt *slice)
{
    int *arr = slice->arr;
    int length = slice->length;
    bool swapped;
    for (int i = 0; i < length; i += 1)
    {
        swapped = false;
        for (int j = 0; j < length - i - 1; j += 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_int(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

// Selection Sort
void sel_sort_int(SliceInt *slice)
{
    if (is_sorted_int(slice) == true)
    {
        return;
    }
    int *arr = slice->arr;
    int length = slice->length;
    int min_index;
    for (int i = 0; i < length; i++)
    {
        int min = INT_MAX;
        for (int j = i; j < length; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                min_index = j;
            }
        }
        if (arr[i] != arr[min_index])
        {
            swap_int(&arr[i], &arr[min_index]);
        }
    }
}

// NOT IMPLEMENTED
void merge_sort_int(SliceInt *slice)
{
    // NOT IMPLEMENTED
}

// this return 2 if the slice is not sorted; else returns the slope.
// -1 -> not descending order
// 0 -> same
// 1-> not ascending order
int order_int(SliceInt *slice)
{
    int *arr = slice->arr;
    int length = slice->length;

    if (length <= 1)
    {
        return 0;
    }
    int order = comp_int(arr[0], arr[1]);
    for (int i = 1; i < length - 1; i++)
    {
        int new_order = comp_int(arr[i], arr[i + 1]);
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

// Returns true if sorted; false otherwise.
bool is_sorted_int(SliceInt *slice)
{
    if (order_int(slice) == 2)
    {
        return false;
    }
    return true;
}

// Merges two sorted slices and returns a new slice.
SliceInt merge_int(SliceInt *a, SliceInt *b)
{
    SliceInt r = new_slice_int((a->length + b->length) * 2);

    int a_length = a->length;
    int b_length = b->length;
    int a_pointer = 0, b_pointer = 0;

    while (a_pointer < a_length && b_pointer < b_length)
    {
        if (a->arr[a_pointer] <= b->arr[b_pointer])
        {
            append_int(&r, a->arr[a_pointer]);
            a_pointer += 1;
        }
        else
        {
            append_int(&r, b->arr[b_pointer]);
            b_pointer += 1;
        }
    }
    for (int i = a_pointer; i < a_length; i++)
    {
        append_int(&r, a->arr[i]);
    }
    for (int i = b_pointer; i < b_length; i++)
    {
        append_int(&r, b->arr[i]);
    }
    return r;
}
