#pragma once

#include "defines.h"

#define RANDOM_MAX ((u64)2 << 31)

typedef struct rng {
  u64 mult;
  u64 inc;
  u64 mod;
  u64 seed;
} RNG;

// initialization
RNG init_rng(u64 seed);
// \return a random number between 0 and RANDOM_MAX
u64 next_rand(RNG *self);
// \return a random number between 0 and max
i32 next_rand_i32(RNG *self, i32 max);
// \return a random floating-point number between 0 and 1
f64 next_randf(RNG *self);
// changes the seed
void set_seed(RNG *self, u64 value);