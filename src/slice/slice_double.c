#include "../include/slice_double.h"

Slice_Double new_slice_double(int capacity)
{
    Slice_Double temp_slice;
    temp_slice.length = 0;
    temp_slice.capacity = capacity;
    temp_slice.w_perm = true;
    temp_slice.arr = (double *)malloc(temp_slice.capacity * sizeof(double));
    init_double(temp_slice.arr, capacity, 0);

    return temp_slice;
}
Slice_Double copy_slice_double(Slice_Double from)
{
}
Slice_Double slice_double_from(Slice_Double *slice, int start, int end, bool w_perm)
{
}
Slice_Double new_slice_double_from(Slice_Double *slice, int start, int end)
{
}

int append_double(Slice_Double *slice, double data)
{
}
int insert_double(Slice_Double *slice, double data, int index)
{
}
int delete_double(Slice_Double *slice, int index)
{
}
int search_double(Slice_Double *slice, double value)
{
}
int bsearch_double(Slice_Double *slice, double value)
{
    // NOT IMPLEMENTED
}
int max_slice_double(Slice_Double *slice)
{
}
int min_slice_double(Slice_Double *slice)
{
}
void display_debug_double(Slice_Double *slice)
{
}
void display_double(Slice_Double *slice)
{
}

int get_double(Slice_Double *slice, int index)
{
}
int set_double(Slice_Double *slice, double value, int index)
{
}
int len_double(Slice_Double *slice)
{
}
int cap_double(Slice_Double *slice)
{
}
void delete_slice_double(Slice_Double *slice)
{
}

/// Increases the capacity when needed. *It does not decrease the capacity*
// Exits with error code EXIT_FAILURE if failed to allocate. 0 otherwise.
int inc_cap_double(Slice_Double *slice)
{
    if (slice->length == slice->capacity && slice->w_perm == true)
    {
        slice->capacity *= 2;
        slice->arr = realloc(slice->arr, slice->capacity * sizeof(int));
        if (slice->arr == NULL)
        {
            exit(EXIT_FAILURE);
        }
        return 0;
    }
    return 0;
}