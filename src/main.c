#include <stdio.h>

#include "include/mylibc.h"

typedef struct rs {
  i32 data1;
  i32 data2;
  i32 data3;
} RS;

void Print_RS(const void *elem) {
  RS *temp = (RS *)elem;
  printf("{%d, %d, %d}", temp->data1, temp->data2, temp->data3);
}

int main() {
  List a = list_new(10, sizeof(RS));
  RS rs1 = {.data1 = 234, .data2 = 2565, .data3 = 92436};
  RS rs2 = {.data1 = 936, .data2 = 7109, .data3 = 1408};
  list_set_print_func(&a, Print_RS);

  for (int i = 0; i < 10; i++) {
    list_append(&a, &rs1);
    list_display(&a);
  }
  list_insert(&a, &rs2, 3);
  list_display(&a);

  list_delete(&a, 3);
  list_display(&a);
  list_delete(&a, 3);
  list_display(&a);

  list_free(&a);
}
s