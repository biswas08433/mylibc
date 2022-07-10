#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#include <math.h>

#define RANDOM_MAX ((long long int)2 << 31)

typedef struct rng
{
    long long int mult;
    long long int inc;
    long long int mod;
    long long int seed;
} RNG;

RNG init_rng(long long int seed);
long long int next_rand(RNG *rng1);
long double next_randf(RNG *rng1);
void set_seed(RNG *rng1, long long int value);

#endif