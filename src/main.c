#include <stdio.h>

#include "include/io.h"

int main()
{
    int n1 = input_int("Enter [1-900]", 1, 900);
    printf("%d", n1);
}