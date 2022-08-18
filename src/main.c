#include <stdio.h>

#include "include/mylibc.h"
#include <time.h>

int main() {
    // time_t t1 = time(NULL);
    RNG rng1 = init_rng(546);

    Stack s = stack_new(20);
    stack_print_handler(&s, print_f64);
    f64 number = next_randf(&rng1);
    u32 size = sizeof(f64);

    for (u32 i = 0; i < 5; i++) {
        number = next_randf(&rng1);
        push(&s, (Object){&number, size});
        stack_display(&s);
    }

    pop(&s, (Object){&number, size});
    printf("popped: %g\n", number);
    stack_display(&s);

    pop(&s, (Object){&number, size});
    printf("popped: %g\n", number);
    stack_display(&s);

    pop(&s, (Object){&number, size});
    printf("popped: %g\n", number);
    stack_display_dbg(&s);

    stack_free(&s);
}