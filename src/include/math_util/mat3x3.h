#pragma once

#include "defines.h"

typedef struct mat3x3 {
    f64 data[9];
} Mat3x3;

// Initialises the matrix to the given value.
Mat3x3 mat3x3_new(f64 value);

f64 get3x3(Mat3x3 self, i32 i, i32 j);
void set3x3(Mat3x3* self, i32 i, i32 j, f64 value);

Mat3x3 add3x3(Mat3x3 a, Mat3x3 b);
Mat3x3 sub3x3(Mat3x3 a, Mat3x3 b);
Mat3x3 mul3x3(Mat3x3 a, Mat3x3 b);