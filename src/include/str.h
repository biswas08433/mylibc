#pragma once

#include "defines.h"

typedef struct str {
    char* data;
    u32 len;
    u32 cap;
} Str;

Str new_str(const char* literal);

void trimSpace(Str* self);