#include "../include/bst.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_NODES 1e6

void fill_bst(Bst **b, int n) {
  for (int i = 0; i < n; i++) {
    *b = bst_add(*b, rand());
  }
}

int calc_mean(Bst *b) {
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += bst_height(b);
  }
  return sum / 10;
}

int min_height(int n) { return floor(log2(n)); }

int main(int argc, char *argv[]) {
  srand(time(NULL));

  Bst *root = bst_new();

  fill_bst(&root, AMOUNT_NODES);
  printf("mean height: %d\n", calc_mean(root));
  printf("minimum height: %d\n", min_height(AMOUNT_NODES));

  bst_free(root);
}
