#include "../include/random.h"

RNG init_rng(long long int seed)
{
    RNG temp = {.mult = 1664525, .inc = 1013904223, .mod = ((long long int)2 << 31), .seed = seed};
    return temp;
}

long long int next_rand(RNG *rng1)
{
    rng1->seed = (rng1->seed * rng1->mult + rng1->inc) % rng1->mod;
    return rng1->seed;
}

long double next_randf(RNG *rng1)
{
    long double v = (long double)next_rand(rng1) / (long double)RANDOM_MAX;
    return v;
}

void set_seed(RNG *rng1, long long int value)
{
    rng1->seed = value;
}