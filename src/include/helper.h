#pragma once

#include "defines.h"

void swap_i32(i32 *a, i32 *b);
void swap_f64(f64 *a, f64 *b);

void swap(void *a, void *b);

i8 comp_i32(i32 a, i32 b);
i8 comp_f64(f64 a, f64 b);

i32 max_i64(i32 a, i32 b);
i32 min_i64(i32 a, i32 b);

f64 max_f64(f64 a, f64 b);
f64 min_f64(f64 a, f64 b);

void init_i32(i32 *arr, u32 length, i32 value);
void init_f64(f64 *arr, u32 length, f64 value);
void init_char(char *arr, u32 length, char value);
void init_bool(b8 *arr, u32 length, b8 value);

void copy_i32(i32 *src, i32 *dest, u32 length);
void copy_f64(f64 *src, f64 *dest, u32 length);
void copy_char(char *from, char *to, u32 length);