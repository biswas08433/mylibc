#include <stdio.h>

#include "dsa/dsa.h"

int main() {
    List temp = list_new_i32(10);
    RNG rng = init_rng(456);

    for (i32 i = 0; i < 500; i++) {
        list_append_i32(&temp, next_rand_i32(&rng, 500));
    }

    list_debug_display(&temp);

    sort_i32(temp);
    list_debug_display(&temp);

    list_free(&temp);
    return 0;
}