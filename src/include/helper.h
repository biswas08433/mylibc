#pragma once
#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void println(const char *line);
void print(const char *line);
void print_arr_int(int *arr, int length);

void swap_int(int *a, int *b);
void swap_float(float *a, float *b);
void swap_dbl(double *a, double *b);

int comp_int(int a, int b);

char *bool_str(bool b);

int max_int(int a, int b);
int min_int(int a, int b);

void init_int(int *arr, int length, int value);
void init_dbl(double *arr, int length, double value);
void init_char(char *arr, int length, int value);
void init_bool(bool *arr, int length, bool value);

void copy_int(int *from, int *to, int length);
void copy_dbl(double *from, double *to, int length);
void copy_char(char *from, char *to, int length);

#endif