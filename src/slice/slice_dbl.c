#include "../include/slice_dbl.h"

double epsilon = 0.00000000000001;

SliceDbl new_slice_dbl(int capacity)
{
    SliceDbl temp_slice;
    temp_slice.length = 0;
    temp_slice.capacity = capacity;
    temp_slice.w_perm = true;
    temp_slice.arr = (double *)malloc(temp_slice.capacity * sizeof(double));
    init_dbl(temp_slice.arr, capacity, 0);

    return temp_slice;
}
SliceDbl copy_slice_dbl(SliceDbl from)
{
    SliceDbl temp_slice = new_slice_dbl(from.capacity);
    temp_slice.length = from.length;
    copy_dbl(from.arr, temp_slice.arr, from.length);
    return temp_slice;
}
SliceDbl slice_dbl_from(SliceDbl *slice, int start, int end, bool w_perm)
{
    SliceDbl new_slice;
    new_slice.length = end - start;
    new_slice.capacity = w_perm ? slice->capacity - start : 0;
    new_slice.w_perm = w_perm;
    new_slice.arr = slice->arr + start;

    return new_slice;
}
SliceDbl new_slice_dbl_from(SliceDbl *slice, int start, int end)
{
    SliceDbl new_slice;
    new_slice.length = end - start;
    new_slice.capacity = new_slice.length * 2;
    new_slice.w_perm = true;
    new_slice.arr = (double *)malloc(new_slice.capacity * sizeof(double));

    if (new_slice.arr == NULL)
    {
        return new_slice;
        fprintf(stderr, "allocation failed!");
    }
    copy_dbl(slice->arr + start, new_slice.arr, new_slice.length);
    return new_slice;
}

int append_dbl(SliceDbl *slice, double data)
{
    if (inc_cap_dbl(slice) == -1)
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
int insert_dbl(SliceDbl *slice, double data, int index)
{
    if (inc_cap_dbl(slice) == -1)
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
int delete_dbl(SliceDbl *slice, int index)
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
int search_dbl(SliceDbl *slice, double value)
{
    for (int i = 0; i < slice->length; i++)
    {
        if (fabs(slice->arr[i] - value) < epsilon)
        {
            return i;
        }
    }
    return -1;
}
int bsearch_dbl(SliceDbl *slice, double value)
{
    // NOT IMPLEMENTED
    return 0;
}
int max_slice_dbl(SliceDbl *slice)
{
    double t = DBL_MIN;
    for (int i = 0; i < slice->length; i++)
    {
        if (slice->arr[i] - t > epsilon)
        {
            t = slice->arr[i];
        }
    }
    return t;
}
int min_slice_dbl(SliceDbl *slice)
{
    double t = DBL_MAX;
    for (int i = 0; i < slice->length; i++)
    {
        if (slice->arr[i] - t < epsilon)
        {
            t = slice->arr[i];
        }
    }
    return t;
}
void display_dbl(SliceDbl *slice)
{
    int length = slice->length;
    double *arr = slice->arr;

    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%.15g", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}");
}
void display_debug_dbl(SliceDbl *slice)
{
    int length = slice->length;
    double *arr = slice->arr;

    printf("{len: %d, ", length);
    printf("cap: %d, [", slice->capacity);
    for (int i = 0; i < length; i++)
    {
        printf("%.15g", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}\n");
}

double get_dbl(SliceDbl *slice, int index)
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
void set_dbl(SliceDbl *slice, double value, int index)
{
    if (index < slice->length)
    {
        slice->arr[index] = value;
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}
int len_dbl(SliceDbl *slice)
{
    return slice->length;
}
int cap_dbl(SliceDbl *slice)
{
    return slice->capacity;
}

void delete_slice_dbl(SliceDbl *slice)
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

/// Increases the capacity when needed. *It does not decrease the capacity*
// Exits with error code EXIT_FAILURE if failed to allocate. 0 otherwise.
int inc_cap_dbl(SliceDbl *slice)
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