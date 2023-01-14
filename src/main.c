#include <stdio.h>

#include "mylibc.h"

int main() {
<<<<<<< HEAD
    // Complex64 a = complex_new(-1.45687, 89.3457);
    // Complex64 b = complex_new(23.345, -6.78);

    complex_display(complex_euler(1.57));

    return 0;
=======
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
>>>>>>> e94f3299efdaab3487acf84208fd67976f1febba
}