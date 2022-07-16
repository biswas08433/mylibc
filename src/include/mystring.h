#pragma once

#include "defines.h"

typedef struct mystring
{
    char *data;
    u32 len;
    u32 cap;
} MyString;

MyString new_string(const char *literal);

char *trimSpace(char *str);
void print_str(MyString *s);