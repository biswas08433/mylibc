#include "../include/random.h"

#include <math.h>

RNG init_rng(u64 seed) {
  RNG temp = {
      .mult = 1664525, .inc = 1013904223, .mod = RANDOM_MAX, .seed = seed};
  return temp;
}

u64 next_rand(RNG *rng1) {
  rng1->seed = (rng1->seed * rng1->mult + rng1->inc) % rng1->mod;
  return rng1->seed;
}

i32 next_rand_i32(RNG *rng, i32 max) {
  i32 temp = (i32)trunc(next_randf(rng) * (f64)max);
  return temp;
}

f64 next_randf(RNG *rng1) {
  f64 v = (f64)next_rand(rng1) / (f64)RANDOM_MAX;
  return v;
}

void set_seed(RNG *rng1, u64 value) { rng1->seed = value; }