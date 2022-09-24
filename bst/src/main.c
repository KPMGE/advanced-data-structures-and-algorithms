// NOTE: fix recursive difference between iterative and recursive approaches

#include "../include/bst.h"
#include "../include/stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_NODES 10

int get_rand_value() { return rand() % (AMOUNT_NODES + 1); }

void fill_bst(Bst **b, int n) {
  for (int i = 1; i < n; i++) {
    *b = bst_add(*b, get_rand_value());
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

void display_node(Bst *b) { printf("%d ", bst_get_value(b)); }

int main(int argc, char *argv[]) {
  srand(time(NULL));

  // Bst *root = bst_new(get_rand_value());
  Bst *root = bst_new(10);
  root = bst_add(root, 5);
  root = bst_add(root, 20);
  root = bst_add(root, 7);
  root = bst_add(root, 15);

  // fill_bst(&root, AMOUNT_NODES);

  // === Recursive ==
  printf("rec_in_order: ");
  bst_rec_in_order(root, display_node);
  printf("\n");

  printf("rec_pre_order: ");
  bst_rec_pre_order(root, display_node);
  printf("\n");

  printf("rec_post_order: ");
  bst_rec_post_order(root, display_node);
  printf("\n\n");

  // === Iterative ==
  printf("iter_pre_order: ");
  bst_iter_pre_order(root, display_node);
  printf("\n");

  printf("iter_in_order: ");
  bst_iter_in_order(root, display_node);
  printf("\n");

  printf("iter_post_order: ");
  bst_iter_post_order(root, display_node);
  printf("\n\n");

  // === Mean and min height ===
  printf("mean height: %d\n", calc_mean(root));
  printf("minimum height: %d\n", min_height(AMOUNT_NODES));

  bst_free(root);
}
