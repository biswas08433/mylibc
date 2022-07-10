#include <stdio.h>

#include "include/mylibc.h"

int main()
{
    int seed = time(NULL);
    // int seed = time(NULL) % RANDOM_MAX;
    RNG rng_main = init_rng(seed);

    SliceDbl a = new_slice_dbl(30);
    SliceDbl b = new_slice_dbl(30);
    display_debug_dbl(&a);
    display_debug_dbl(&b);

    for (int i = 0; i < 40; i++)
    {
        double r1 = next_randf(&rng_main);
        double r2 = next_randf(&rng_main);

        append_dbl(&a, r1);
        append_dbl(&b, r2);
    }

    display_debug_dbl(&a);
    display_debug_dbl(&b);

    delete_slice_dbl(&a);
    delete_slice_dbl(&b);
    return 0;
}