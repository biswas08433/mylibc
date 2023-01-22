#include "dsa/sort.h"

void quicksort_i32(List l) {
    if (l.length <= 1) {
        return;
    }
    RNG rng = init_rng(123);
    i32 i = 0, j = l.length, pivot = next_rand_i32(&rng, l.length);

    while (i <= j) {
        while (list_get_i32(&l, i) < list_get_i32(&l, pivot)) {
            i += 1;
        }
        while (list_get_i32(&l, j) < list_get_i32(&l, pivot)) {
            j -= 1;
        }
        swap_i32(list_get(&l, i), list_get(&l, j));
    }
    list_swap(&l, j, pivot);
    pivot = j;
    quicksort_i32(list_slice(&l, 0, pivot, TRUE));
    quicksort_i32(list_slice(&l, pivot + 1, l.length, TRUE));
}