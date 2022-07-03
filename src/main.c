#include <stdio.h>
#include "include/main.h"

int main()
{
    Slice_Int slice1 = new_slice_int(20);
    Slice_Int slice2 = new_slice_int(20);
    for (int i = 1; i < 10; i++)
    {
        append_int(&slice1, rand() % 100);
        append_int(&slice2, rand() % 100);
    }
    display_debug_int(&slice1);
    display_debug_int(&slice2);

    Slice_Int slice3 = new_slice_int_from(&slice1, 2, 5);
    display_debug_int(&slice3);

    append_int(&slice3, 45);
    append_int(&slice3, 32);
    append_int(&slice3, 98);

    display_debug_int(&slice1);
    display_debug_int(&slice2);
    display_debug_int(&slice3);

    delete_slice_int(&slice1);
    delete_slice_int(&slice2);
    delete_slice_int(&slice3);
    return 0;
}