#include "math_util/mat3x3.h"
#include "helper.h"

#include <stdlib.h>

Mat3x3 mat3x3_new(f64 value) {
    Mat3x3 temp;
    init_f64(temp.data, 9, value);
    return temp;
}

f64 get3x3(Mat3x3 self, i32 i, i32 j) {
    return self.data[3 * i + j];
}
void set3x3(Mat3x3* self, i32 i, i32 j, f64 value) {
    self->data[3 * i + j] = value;
}

Mat3x3 add3x3(Mat3x3 a, Mat3x3 b) {
    Mat3x3 temp = mat3x3_new(0);
    for (size_t i = 0; i < 9; i++) {
        temp.data[i] = a.data[i] + b.data[i];
    }
    return temp;
}
Mat3x3 sub3x3(Mat3x3 a, Mat3x3 b) {
    Mat3x3 temp = mat3x3_new(0);
    for (size_t i = 0; i < 9; i++) {
        temp.data[i] = a.data[i] - b.data[i];
    }
    return temp;
}
Mat3x3 mul3x3(Mat3x3 a, Mat3x3 b) {
    Mat3x3 temp = mat3x3_new(0);
    for (size_t i = 0; i < 9; i++) {
        temp.data[i] = a.data[i] - b.data[i];
    }
    return temp;
}