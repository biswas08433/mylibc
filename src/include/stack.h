#pragma once

typedef struct {
  void* data;
  int top;
  int totalElements;
  int memberSize;
} Stack;