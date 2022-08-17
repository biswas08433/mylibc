#include "../include/random.h"

#include <math.h>

RNG init_rng(u64 seed) {
  RNG temp = {.mult = 1664525, .inc = 1013904223, .mod = RANDOM_MAX, .seed = seed};
  return temp;
}

u64 next_rand(RNG *self) {
  self->seed = (self->seed * self->mult + self->inc) % self->mod;
  return self->seed;
}

i32 next_rand_i32(RNG *rng, i32 max) {
  i32 temp = (i32)trunc(next_randf(rng) * (f64)max);
  return temp;
}

f64 next_randf(RNG *self) {
  f64 v = (f64)next_rand(self) / (f64)RANDOM_MAX;
  return v;
}

void set_seed(RNG *self, u64 value) { self->seed = value; }