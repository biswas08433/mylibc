#include "../include/slice_f64.h"
#include "../include/helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

Slice_f64 slice_new_f64(u32 capacity)
{
    Slice_f64 temp_slice;
    temp_slice.length = 0;
    temp_slice.capacity = capacity;
    temp_slice.w_perm = TRUE;
    temp_slice.arr = (f64 *)malloc(temp_slice.capacity * sizeof(f64));
    init_f64(temp_slice.arr, capacity, 0);

    return temp_slice;
}
Slice_f64 copy_slice_f64(Slice_f64 from)
{
    Slice_f64 temp_slice = slice_new_f64(from.capacity);
    temp_slice.length = from.length;
    copy_f64(from.arr, temp_slice.arr, from.length);
    return temp_slice;
}
Slice_f64 slice_from_f64(Slice_f64 *self, u32 start, u32 end, b8 w_perm)
{
    Slice_f64 new_slice;
    new_slice.length = end - start;
    new_slice.capacity = w_perm ? self->capacity - start : 0;
    new_slice.w_perm = w_perm;
    new_slice.arr = self->arr + start;

    return new_slice;
}
Slice_f64 slice_new_from_f64(Slice_f64 *self, u32 start, u32 end)
{
    Slice_f64 new_slice;
    new_slice.length = end - start;
    new_slice.capacity = new_slice.length * 2;
    new_slice.w_perm = TRUE;
    new_slice.arr = (f64 *)malloc(new_slice.capacity * sizeof(f64));

    if (new_slice.arr == NULL)
    {
        return new_slice;
        fprintf(stderr, "allocation failed!");
    }
    copy_f64(self->arr + start, new_slice.arr, new_slice.length);
    return new_slice;
}

u32 append_f64(Slice_f64 *self, f64 data)
{
    if (update_cap_f64(self, FALSE) == -1)
    {
        return -1;
    }
    if (self->w_perm == TRUE)
    {
        self->arr[self->length] = data;
        self->length += 1;
        return self->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}
u32 insert_f64(Slice_f64 *self, f64 data, u32 index)
{
    if (update_cap_f64(self, FALSE) == -1)
    {
        return -1;
    }
    if (self->w_perm == TRUE)
    {
        for (u32 i = self->length - 1; i > index; i -= 1)
        {
            self->arr[i + 1] = self->arr[i];
        }
        self->arr[index] = data;
        self->length += 1;
        return self->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}
u32 delete_f64(Slice_f64 *self, u32 index)
{
    if (self->w_perm == TRUE)
    {
        for (u32 i = index; i < self->length + 1; i += 1)
        {
            self->arr[i] = self->arr[i + 1];
        }
        self->length -= 1;
        update_cap_f64(self, TRUE);
        return self->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}
u32 search_f64(Slice_f64 *self, f64 value)
{
    for (u32 i = 0; i < self->length; i++)
    {
        if (fabs(self->arr[i] - value) < DBL_EPSILON)
        {
            return i;
        }
    }
    return -1;
}
u32 bsearch_f64(Slice_f64 *self, f64 value)
{
    // NOT IMPLEMENTED
    return 0;
}
u32 slice_max_f64(Slice_f64 *self)
{
    f64 t = DBL_MIN;
    for (u32 i = 0; i < self->length; i++)
    {
        if (self->arr[i] - t > DBL_EPSILON)
        {
            t = self->arr[i];
        }
    }
    return t;
}
u32 slice_min_f64(Slice_f64 *self)
{
    f64 t = DBL_MAX;
    for (u32 i = 0; i < self->length; i++)
    {
        if (self->arr[i] - t < DBL_EPSILON)
        {
            t = self->arr[i];
        }
    }
    return t;
}
void display_f64(Slice_f64 *self)
{
    u32 length = self->length;
    f64 *arr = self->arr;

    printf("[");
    for (u32 i = 0; i < length; i++)
    {
        printf("%.15g", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}");
}
void display_debug_f64(Slice_f64 *self)
{
    u32 length = self->length;
    f64 *arr = self->arr;

    printf("{len: %d, ", length);
    printf("cap: %d, [", self->capacity);
    for (u32 i = 0; i < length; i++)
    {
        printf("%.15g", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}\n");
}

f64 get_f64(Slice_f64 *self, u32 index)
{
    if (index < self->length)
    {
        return self->arr[index];
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}
void set_f64(Slice_f64 *self, f64 value, u32 index)
{
    if (index < self->length)
    {
        self->arr[index] = value;
    }
    else
    {
        printf("Accessing invalid index %d", index);
        exit(EXIT_FAILURE);
    }
}
u32 len_f64(Slice_f64 *self)
{
    return self->length;
}
u32 cap_f64(Slice_f64 *self)
{
    return self->capacity;
}

void slice_free_f64(Slice_f64 *self)
{
    if (self->w_perm == TRUE)
    {
        free(self->arr);
        self->arr = NULL;
    }
    else
    {
        fprintf(stderr, "Write denied!");
        exit(EXIT_FAILURE);
    }
}
u32 update_cap_f64(Slice_f64 *self, b8 can_shrink)
{
    if (self->length == self->capacity && self->w_perm == TRUE)
    {
        self->capacity *= 2;
    }
    else if (self->length <= (self->capacity / 2) && self->w_perm == TRUE && can_shrink)
    {
        self->capacity /= 2;
    }
    self->arr = (f64 *)realloc(self->arr, self->capacity * sizeof(f64));
    if (self->arr == NULL)
    {
        return FALSE;
    }
    return TRUE;
}