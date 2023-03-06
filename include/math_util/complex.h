#pragma once

#include "defines.h"

typedef struct complex64 {
    f64 real;
    f64 imag;
    f64 rad;
    f64 theta;
} Complex64;

Complex64 complex_new(f64 r, f64 i);

Complex64 complex_add(Complex64 a, Complex64 b);
Complex64 complex_sub(Complex64 a, Complex64 b);
Complex64 complex_mul(Complex64 a, Complex64 b);
Complex64 complex_div(Complex64 a, Complex64 b);

f64 complex_argument(Complex64 self);
Complex64 complex_euler(f64 theta);

void complex_display(Complex64 self);
