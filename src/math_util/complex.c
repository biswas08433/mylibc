#include "math_util/complex.h"

#include <stdio.h>
#include <math.h>

Complex64 complex_new(f64 r, f64 i)
{
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};
    temp.real = r;
    temp.imag = i;

    temp.rad = sqrt(r * r + i * i);
    temp.theta = atan2(i, r);
    return temp;
}

Complex64 complex_add(Complex64 a, Complex64 b)
{
    return complex_new(a.real + b.real, a.imag + b.imag);
}
Complex64 complex_sub(Complex64 a, Complex64 b)
{
    return complex_new(a.real - b.real, a.imag - b.imag);
}
Complex64 complex_mul(Complex64 a, Complex64 b)
{
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};
    temp.rad = a.rad * b.rad;
    temp.theta = a.theta + b.theta;

    if (temp.theta > PI)
    {
        temp.theta = -(TAU - temp.theta);
    }
    else if (temp.theta < -PI)
    {
        temp.theta = TAU + temp.theta;
    }

    temp.real = temp.rad * cos(temp.theta);
    temp.imag = temp.rad * sin(temp.theta);
    return temp;
}
Complex64 complex_div(Complex64 a, Complex64 b)
{
    Complex64 temp = (Complex64){0.0, 0.0, 0.0, 0.0};

    if (b.rad == 0)
    {
        fprintf(stderr, "Exception: Division by Zero");
        return temp;
    }
    temp.rad = a.rad / b.rad;
    temp.theta = a.theta - b.theta;
    if (temp.theta > PI)
    {
        temp.theta = -(TAU - temp.theta);
    }
    else if (temp.theta < -PI)
    {
        temp.theta = TAU + temp.theta;
    }
    temp.real = temp.rad * cos(temp.theta);
    temp.imag = temp.rad * sin(temp.theta);
    return temp;
}
Complex64 complex_polar(f64 r, f64 theta)
{
    return (Complex64){r * cos(theta), r * sin(theta), r, theta};
}

void complex_display(Complex64 self)
{
    printf("(%.3f, %.3f, %.3f, %.3f)\n", self.real, self.imag, self.rad, self.theta);
}
