#include <stdio.h>

#include "include/mylibc.h"
#include <time.h>

int main() {
    time_t t1 = time(NULL);
    RNG r = init_rng(t1);
    List l = list_new_i32(30);

    for (i32 i = 0; i < 30; i++) {
        i32 n = next_rand_i32(&r, 5000);
        list_append_i32(&l, n);
    }
    //  list_display(&l);
    printf("Sum: %d\n", list_sum_i32(&l));

    list_free(&l);
}