#pragma once

#include "defines.h"

typedef struct string {
  char *data;
  u32 len;
  u32 cap;
} String;

String new_string(const char *literal);

void trimSpace(String *self);