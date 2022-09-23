#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))

struct bst {
  int value;
  Bst *left;
  Bst *right;
};

Bst *bst_new(int v) {
  Bst *b = malloc(sizeof(Bst));
  b->left = b->right = NULL;
  b->value = v;
  return b;
}

Bst *bst_add(Bst *b, int v) {
  if (!b)
    return bst_new(v);
  if (b->value < v)
    b->left = bst_add(b->left, v);
  if (b->value > v)
    b->right = bst_add(b->right, v);
  return b;
}

void bst_free(Bst *b) {
  if (b) {
    bst_free(b->left);
    bst_free(b->right);
    free(b);
  }
}

int bst_height(Bst *b) {
  if (!b)
    return -1;
  int left_height = bst_height(b->left);
  int right_height = bst_height(b->right);
  return MAX(left_height, right_height) + 1;
}
