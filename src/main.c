#include <stdio.h>

#include "include/mylibc.h"
#include <time.h>

int main() {
    // time_t t1 = time(NULL);
    RNG rng1 = init_rng(546);

    Queue s = queue_new(20);
    queue_print_handler(&s, print_f64);
    queue_display(&s);
    f64 number = next_randf(&rng1);
    u32 size = sizeof(f64);

    for (u32 i = 0; i < 5; i++) {
        number = next_randf(&rng1);
        enq(&s, (Object){&number, size});
        queue_display(&s);
    }

    deq(&s, (Object){&number, size});
    printf("dequed: %g\n", number);
    queue_display_dbg(&s);

    deq(&s, (Object){&number, size});
    printf("dequed: %g\n", number);
    queue_display(&s);

    deq(&s, (Object){&number, size});
    printf("dequed: %g\n", number);
    queue_display(&s);

    queue_free(&s);
}