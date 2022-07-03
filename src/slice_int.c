#include "include/slice_int.h"

// Returns a new slice of int.
Slice_Int new_slice_int(int capacity)
{
    Slice_Int temp_slice;
    temp_slice.length = 0;
    temp_slice.capacity = capacity;
    temp_slice.w_perm = true;
    temp_slice.arr = (int *)malloc(temp_slice.capacity * sizeof(int));
    init_int(temp_slice.arr, capacity, 0);

    return temp_slice;
}

// Returns a copy slice from another slice.
Slice_Int copy_slice_int(Slice_Int from)
{
    Slice_Int temp_slice = new_slice_int(from.capacity);
    temp_slice.length = from.length;
    copy_int(from.arr, temp_slice.arr, from.length);
    return temp_slice;
}

// Creates a new slice from existing slice. The underlying array will be shared.
// w_perm set the write permission.
// range -> [start,end)
Slice_Int slice_int_from(Slice_Int *slice, int start, int end, bool w_perm)
{
    Slice_Int new_slice;
    new_slice.length = end - start;
    new_slice.capacity = w_perm ? slice->capacity - start : 0;
    new_slice.w_perm = w_perm;
    new_slice.arr = slice->arr + start;

    return new_slice;
}

// Creates a new slice from existing slice. The underlying array will be newly allocated.
// range -> [start,end)
Slice_Int new_slice_int_from(Slice_Int *slice, int start, int end)
{
    Slice_Int new_slice;
    new_slice.length = end - start;
    new_slice.capacity = new_slice.length * 2;
    new_slice.w_perm = true;
    new_slice.arr = (int *)malloc(new_slice.capacity * sizeof(int));

    if (new_slice.arr == NULL)
    {
        return new_slice;
        fprintf(stderr, "allocation failed!");
    }
    copy_int(slice->arr + start, new_slice.arr, new_slice.length);
    return new_slice;
}

// Append an element to the slice. Returns the updated length or -1 if error.
int append_int(Slice_Int *slice, int data)
{
    if (check_capacity_int(slice) == -1)
    {
        return -1;
    }
    if (slice->w_perm == true)
    {
        slice->arr[slice->length] = data;
        slice->length += 1;
        return slice->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

// Insert data into given index.Returns the updated length or -1 if error.
int insert_int(Slice_Int *slice, int data, int index)
{
    if (check_capacity_int(slice) == -1)
    {
        return -1;
    }
    if (slice->w_perm == true)
    {
        for (int i = slice->length - 1; i > index; i -= 1)
        {
            slice->arr[i + 1] = slice->arr[i];
        }
        slice->arr[index] = data;
        slice->length += 1;
        return slice->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

// Deletes the data at given index. Returns the updated length.
int delete_int(Slice_Int *slice, int index)
{
    if (slice->w_perm == true)
    {
        for (int i = index; i < slice->length + 1; i += 1)
        {
            slice->arr[i] = slice->arr[i + 1];
        }
        slice->length -= 1;
        return slice->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

// Seraches for the data. Returns -1 if not found.
int search_int(Slice_Int *slice, int value)
{
    for (int i = 0; i < slice->length; i++)
    {
        if (slice->arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int max_slice_int(Slice_Int *slice)
{
    int t = INT_MIN;
    for (int i = 0; i < slice->length; i++)
    {
        if (slice->arr[i] > t)
        {
            t = slice->arr[i];
        }
    }
    return t;
}

int min_slice_int(Slice_Int *slice)
{
    int t = INT_MAX;
    for (int i = 0; i < slice->length; i++)
    {
        if (slice->arr[i] < t)
        {
            t = slice->arr[i];
        }
    }
    return t;
}

void display_int(Slice_Int *slice)
{
    int length = slice->length;
    int *arr = slice->arr;

    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}");
}

void display_debug_int(Slice_Int *slice)
{
    int length = slice->length;
    int *arr = slice->arr;

    printf("{len: %d, ", length);
    printf("cap: %d, [", slice->capacity);
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}\n");
}
