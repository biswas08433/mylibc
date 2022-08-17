#include <stdio.h>

#include "include/mylibc.h"
#include <time.h>

int main() {
  time_t t1 = time(NULL);
  RNG rng1 = init_rng(t1);
  f64 number = next_randf(&rng1);

  LList l1 = llist_new();
  llist_default_print_func(&l1, print_f64);
  Object bucket;
  bucket.data = &number;
  bucket.size = sizeof(f64);
  llist_append(&l1, bucket);
  number = next_randf(&rng1);
  llist_append(&l1, bucket);

  llist_display_dbg(&l1);

  for (size_t i = 0; i < 6; i++) {
    number = next_randf(&rng1);
    llist_append(&l1, bucket);
  }

  llist_display_dbg(&l1);

  number = next_randf(&rng1);
  llist_prepend(&l1, bucket);

  llist_display_dbg(&l1);

  llist_free(&l1);
}