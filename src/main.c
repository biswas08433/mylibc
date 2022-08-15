#include <stdio.h>

#include "include/mylibc.h"
#include <time.h>

int main() {
  time_t t1 = time(NULL);
  RNG rng1 = init_rng(t1);

  List_i32 l1 = list_new_i32(10);
  list_append_i32(&l1, next_rand_i32(&rng1, 1000));
  list_append_i32(&l1, next_rand_i32(&rng1, 1000));

  list_display_dbg_i32(&l1);

  for (size_t i = 0; i < 40; i++) {
    list_append_i32(&l1, next_rand_i32(&rng1, 100000));
  }
  list_display_dbg_i32(&l1);

  list_free_i32(&l1);
}