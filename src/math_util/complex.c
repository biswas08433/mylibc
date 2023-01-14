#include "math_util/complex.h"

#include <stdio.h>
#include <math.h>

Complex64 complex_new(f64 r, f64 i) {
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};
    temp.real = r;
    temp.imag = i;

    temp.rad = sqrt(pow(r, 2) + pow(i, 2));
    temp.theta = atan2(i, r);
    return temp;
}

Complex64 complex_add(Complex64 a, Complex64 b) {
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    temp.rad = sqrt(pow(temp.real, 2) + pow(temp.imag, 2));
    temp.theta = atan2(temp.imag, temp.real);
    return temp;
}
Complex64 complex_sub(Complex64 a, Complex64 b) {
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};
    temp.real = a.real - b.real;
    temp.imag = a.imag - b.imag;
    temp.rad = sqrt(pow(temp.real, 2) + pow(temp.imag, 2));
    temp.theta = atan2(temp.imag, temp.real);
    return temp;
}
Complex64 complex_mul(Complex64 a, Complex64 b) {
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};
    temp.rad = a.rad * b.rad;
    temp.theta = a.theta + b.theta;
    temp.real = temp.rad * cos(temp.theta);
    temp.imag = temp.rad * sin(temp.theta);
    return temp;
}
Complex64 complex_div(Complex64 a, Complex64 b) {
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};

    // TODO: Assuming b.rad != zero
    temp.rad = a.rad / b.rad;
    temp.theta = a.theta - b.theta;
    temp.real = temp.rad * cos(temp.theta);
    temp.imag = temp.rad * sin(temp.theta);
    return temp;
}

f64 complex_argument(Complex64 self) {
    return self.rad;
}

Complex64 complex_euler(f64 theta){
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};

    // TODO: Assuming b.rad != zero
    temp.real = cos(theta);
    temp.imag = sin(theta);
    temp.rad = 1;
    temp.theta = theta;
    return temp;
}

void complex_display(Complex64 self) {
    printf("{(%.8g, %.8g i), (%.8g, %.8g)}", self.real, self.imag, self.rad, self.theta);
}
