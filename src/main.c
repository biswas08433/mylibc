#include <stdio.h>

#include "mylibc.h"

int main() {
    // Complex64 a = complex_new(-1.45687, 89.3457);
    // Complex64 b = complex_new(23.345, -6.78);

    complex_display(complex_euler(1.57));

    return 0;
}