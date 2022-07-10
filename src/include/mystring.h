#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct mystring
{
    char *data;
    int len;
    int cap;
} MyString;

MyString new_string(const char *literal);

char *trimSpace(char *str);
void print_string(MyString *s);

#endif