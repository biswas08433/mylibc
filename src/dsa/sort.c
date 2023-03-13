#include "dsa/sort.h"

#include <stdio.h>
#include <stdlib.h>

// i32 demo_partition_i32(List l, i32 pivot_index)
// {
//     i32 i = -1, j = 0;
//     i32 pivot_val = list_get_i32(&l, pivot_index);
//     while (j < pivot_index)
//     {
//         if (list_get_i32(&l, j) < pivot_val)
//         {
//             i += 1;
//             if (i != j)
//                 list_swap(&l, i, j);
//         }
//         j += 1;
//     }
//     list_swap(&l, i + 1, pivot_index);
//     return i + 1;
// }

// void demo_sort_i32(List l)
// {
//     if (l.length <= 1)
//     {
//         return;
//     }

//     i32 p = partition_i32(l, l.length - 1);
//     sort_i32(list_slice(&l, 0, p, TRUE));
//     sort_i32(list_slice(&l, p + 1, l.length, TRUE));
// }

void list_sort_i32()
{
}

void list_sort_f64(List *self)
{
    qsort(self->arr, self->length, self->elem_size, compare_f64);
}
