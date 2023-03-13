#include <stdio.h>
#include "mylibc.h"

void test_complex()
{
    Complex64 c1 = complex_new(5, 0);
    Complex64 c2 = complex_new(5, 8.9);
    complex_display(c1);
    complex_display(c2);

    c1 = complex_mul(c1, c2);
    complex_display(c1);
    c1 = complex_mul(c1, c2);
    complex_display(c1);
    c1 = complex_mul(c1, c2);
    complex_display(c1);
    c1 = complex_div(c1, c2);
    complex_display(c1);
    c1 = complex_div(c1, c2);
    complex_display(c1);
}

void test_list()
{
    List l = list_new_f64(100);
    list_append_f64(&l, 12.956);
    list_append_f64(&l, 23.65);
    list_append_f64(&l, 56.45);
    list_append_f64(&l, 1.34);
    list_append_f64(&l, 9.98);
    list_append_f64(&l, 4.56);
    list_append_f64(&l, 12.956);
    list_debug_display(&l);

    list_sort_f64(&l);
    list_debug_display(&l);
    list_free(&l);
}

int main(int argc, char const *argv[])
{
    test_list();
}
