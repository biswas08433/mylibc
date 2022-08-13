#include "../include/slice_i32.h"
#include "../include/helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

Slice_i32 slice_new_i32(u32 capacity)
{
    Slice_i32 temp_slice;
    temp_slice.length = 0;
    temp_slice.capacity = capacity;
    temp_slice.w_perm = TRUE;
    temp_slice.arr = (i32 *)malloc(temp_slice.capacity * sizeof(i32));
    init_i32(temp_slice.arr, capacity, 0);

    return temp_slice;
}

Slice_i32 slice_copy_i32(Slice_i32 from)
{
    Slice_i32 temp_slice = slice_new_i32(from.capacity);
    temp_slice.length = from.length;
    copy_i32(from.arr, temp_slice.arr, from.length);
    return temp_slice;
}

Slice_i32 slice_from_i32(Slice_i32 *self, u32 start, u32 end, b8 w_perm)
{
    Slice_i32 new_slice;
    new_slice.length = end - start;
    new_slice.capacity = w_perm ? self->capacity - start : 0;
    new_slice.w_perm = w_perm;
    new_slice.arr = self->arr + start;

    return new_slice;
}

Slice_i32 slice_new_from_i32(Slice_i32 *self, u32 start, u32 end)
{
    Slice_i32 new_slice;
    new_slice.length = end - start;
    new_slice.capacity = new_slice.length * 2;
    new_slice.w_perm = TRUE;
    new_slice.arr = (i32 *)malloc(new_slice.capacity * sizeof(i32));

    if (new_slice.arr == NULL)
    {
        return new_slice;
        fprintf(stderr, "allocation failed!");
    }
    copy_i32(self->arr + start, new_slice.arr, new_slice.length);
    return new_slice;
}

u32 append_i32(Slice_i32 *self, i32 data)
{
    if (update_cap_i32(self, FALSE) == FALSE)
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

u32 insert_i32(Slice_i32 *self, i32 data, u32 index)
{
    if (update_cap_i32(self, FALSE) == -1)
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

u32 delete_i32(Slice_i32 *self, u32 index)
{
    if (self->w_perm == TRUE)
    {
        for (u32 i = index; i < self->length + 1; i += 1)
        {
            self->arr[i] = self->arr[i + 1];
        }
        self->length -= 1;
        update_cap_i32(self, TRUE);
        return self->length;
    }
    else
    {
        fprintf(stderr, "Write denied!\n");
        exit(EXIT_FAILURE);
    }
}

u32 search_i32(Slice_i32 *self, i32 value)
{
    for (u32 i = 0; i < self->length; i++)
    {
        if (self->arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// TODO:bsearch_i32
u32 bsearch_i32(Slice_i32 *self, i32 value)
{
    // Not IMPLEMENTED
    return 0;
}

i32 max_slice_i32(Slice_i32 *self)
{
    i32 t = INT_MIN;
    for (u32 i = 0; i < self->length; i++)
    {
        if (self->arr[i] > t)
        {
            t = self->arr[i];
        }
    }
    return t;
}

i32 min_slice_i32(Slice_i32 *self)
{
    i32 t = INT_MAX;
    for (u32 i = 0; i < self->length; i++)
    {
        if (self->arr[i] < t)
        {
            t = self->arr[i];
        }
    }
    return t;
}

void display_i32(Slice_i32 *self)
{
    u32 length = self->length;
    i32 *arr = self->arr;

    printf("[");
    for (u32 i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}");
}

void display_debug_i32(Slice_i32 *self)
{
    u32 length = self->length;
    i32 *arr = self->arr;

    printf("{len: %d, ", length);
    printf("cap: %d, [", self->capacity);
    for (u32 i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
        if (i != length - 1)
            printf(" ");
    }
    printf("]}\n");
}

i32 get_i32(Slice_i32 *self, u32 index)
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

void set_i32(Slice_i32 *self, i32 value, u32 index)
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

u32 len_i32(Slice_i32 *self)
{
    return self->length;
}

u32 cap_i32(Slice_i32 *self)
{
    return self->capacity;
}

void slice_free_i32(Slice_i32 *self)
{
    if (self->w_perm == TRUE && self->arr != NULL)
    {
        free(self->arr);
        self->arr = NULL;
    }
}

b8 update_cap_i32(Slice_i32 *self, b8 can_shrink)
{
    if (self->length == self->capacity && self->w_perm == TRUE)
    {
        self->capacity *= 2;
        self->arr = (i32 *)realloc(self->arr, self->capacity * sizeof(i32));
        if (self->arr == NULL)
        {
            return FALSE;
        }
    }
    else if (self->length < (self->capacity / 2) && self->w_perm == TRUE && can_shrink)
    {
        self->capacity /= 2;
        self->arr = (i32 *)realloc(self->arr, self->capacity * sizeof(i32));
        if (self->arr == NULL)
        {
            return FALSE;
        }
    }
    return TRUE;
}
