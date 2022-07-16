#include <stdio.h>

#include "include/mylibc.h"

int main()
{
    RNG rng_main = init_rng(0);

    LList_f64 a = llist_new_f64();
    display_debug_llist_f64(&a);

    for (int i = 0; i < 10; i++)
    {
        f64 r1 = next_randf(&rng_main);
        llist_prepend_f64(&a, r1);
        display_debug_llist_f64(&a);
    }

    display_debug_llist_f64(&a);
    llist_delete_f64(&a);
    return 0;
}