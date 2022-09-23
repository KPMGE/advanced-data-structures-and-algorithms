#include "../include/bst.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_NODES 10

void fill_bst(Bst **b, int n) {
  for (int i = 1; i < n; i++) {
    *b = bst_add(*b, i);
    //*b = bst_add(*b, rand());
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

void display_node(Bst *b) {
	if (!b) return;
	printf("%d ", bst_get_value(b));
}


int main(int argc, char *argv[]) {
  srand(time(NULL));

  Bst *root = bst_new(0);

  fill_bst(&root, AMOUNT_NODES);

  printf("in_order: \n");
	bst_rec_in_order(root, display_node);
	printf("\n");


  printf("pre_order:\n");
	bst_rec_pre_order(root, display_node);
	printf("\n");

  printf("post_order:\n");
	bst_rec_post_order(root, display_node);
	printf("\n");


  printf("mean height: %d\n", calc_mean(root));
  printf("minimum height: %d\n", min_height(AMOUNT_NODES));

  bst_free(root);
}
