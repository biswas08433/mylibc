#pragma once

#include "defines.h"

typedef struct tnode {
    Object core;
    struct tnode* left;
    struct tnode* right;
} TNode;

typedef struct bintree {
    TNode* root;
    u32 height;  // Number of layers
    u32 size;    // Number of nodes
} BinTree;


