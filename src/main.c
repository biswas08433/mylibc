#include <stdio.h>

#include "include/mylibc.h"
#include <time.h>

int main() {
    // time_t t1 = time(NULL);
    RNG rng1 = init_rng(546);

    LList l = llist_new(20);
    llist_display(&l);
    f64 number = next_randf(&rng1);
    llist_append_f64(&l, number);

    for (u32 i = 0; i < 5; i++) {
        number = next_randf(&rng1);
        llist_append_f64(&l, number);
        llist_display(&l);
    }
    llist_append_i32(&l, 457);
    llist_append_b8(&l, 'T');
    llist_append_b8(&l, 'R');
    llist_append_b8(&l, 'U');
    llist_append_b8(&l, 'C');
    llist_append_b8(&l, 'K');
    llist_display(&l);

    llist_free(&l);
}