#include "math_util/stat.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

f64 mean_f64(List* arr, i32 n) {
    f64 sum = 0;
    for (i32 i = 0; i < n; i++) {
        sum = sum + list_get_f64(arr, i);
    }
    return sum / n;
}