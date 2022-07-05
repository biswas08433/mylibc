#pragma once
#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdbool.h>

void println(const char *line);
void print(const char *line);

void swap_int(int *a, int *b);
void swap_float(float *a, float *b);
void swap_double(double *a, double *b);

int comp_int(int a, int b);

char *bool_str(bool b);

int max_int(int a, int b);
int min_int(int a, int b);

void init_int(int *arr, int length, int value);
void copy_int(int *from, int *to, int length);

void init_double(double *arr, int length, double value);
void copy_double(double *from, double *to, int length);

#endif