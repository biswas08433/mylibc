#pragma once

#include "defines.h"

Complex64 complex_new(f64 re, f64 im);

Complex64 complex_add(Complex64 a, Complex64 b);
Complex64 complex_sub(Complex64 a, Complex64 b);
Complex64 complex_mul(Complex64 a, Complex64 b);
Complex64 complex_div(Complex64 a, Complex64 b);

Complex64 complex_polar(f64 r, f64 t);

void complex_display(Complex64 self);
