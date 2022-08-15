#pragma once

#include "defines.h"

#define RANDOM_MAX ((u64)2 << 31)

typedef struct rng {
  u64 mult;
  u64 inc;
  u64 mod;
  u64 seed;
} RNG;

RNG init_rng(u64 seed);
u64 next_rand(RNG *rng1);
i32 next_rand_i32(RNG *rng, i32 max);

f64 next_randf(RNG *rng1);

void set_seed(RNG *rng1, u64 value);