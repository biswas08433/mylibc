#include "../include/slice_int.h"

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
    if (inc_cap_int(slice) == -1)
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

// Insert data into given index. Returns the updated length or -1 if error.
int insert_int(Slice_Int *slice, int data, int index)
{
    if (inc_cap_int(slice) == -1)
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

// Searches for the data. Returns -1 if not found.
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

// NOT IMPLEMENTED
int bsearch_int(Slice_Int *slice, int value)
{
    // Not IMPLEMENTED
    return 0;
}

// Returns the maximum element from the slice.
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

// Returns the minimum element from the slice.
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

// Display the slice.
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

// Display the slice with debug info.
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

// Gets the element by the given index.
int get_int(Slice_Int *slice, int index)
{
    if (index < slice->length)
    {
        return slice->arr[index];
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}

// Sets the element by the given index.
int set_int(Slice_Int *slice, int value, int index)
{
    if (index < slice->length)
    {
        return slice->arr[index];
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}

// Returns the length of the slice.
int len_int(Slice_Int *slice)
{
    return slice->length;
}

// Returns the capacity of the slice.
int cap_int(Slice_Int *slice)
{
    return slice->capacity;
}

// Frees the slice's underlying array.
// Only delete the original slice i.e. the slice containing the starting pointer.
void delete_slice_int(Slice_Int *slice)
{
    if (slice->w_perm == true)
    {
        free(slice->arr);
        slice->arr = NULL;
    }
    else
    {
        fprintf(stderr, "Write denied!");
        exit(EXIT_FAILURE);
    }
}



// Increases the capacity when needed. *It does not decrease the capacity*
// Returns -1 if there is error in allocation. 0 otherwise.
int inc_cap_int(Slice_Int *slice)
{
    if (slice->length == slice->capacity && slice->w_perm == true)
    {
        slice->capacity *= 2;
        int *new_arr = (int *)malloc(slice->capacity * sizeof(int));
        if (new_arr == NULL)
        {
            return -1;
        }
        copy_int(new_arr, slice->arr, slice->length);
        free(slice->arr);
        slice->arr = new_arr;
        return 0;
    }
    return 0;
}
