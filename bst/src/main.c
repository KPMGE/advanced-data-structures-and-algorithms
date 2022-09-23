#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_bst(Bst *b, int n) {
  for (int i = 0; i < n; i++) {
    bst_add(b, rand());
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  Bst *b = bst_new();

  fill_bst(b, 1e6);
  printf("height: %d\n", bst_height(b));

  bst_free(b);
}
