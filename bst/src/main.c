// NOTE: fix recursive difference between iterative and recursive approaches

#include "../include/bst.h"
#include "../include/queue.h"
#include "../include/stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AMOUNT_NODES (int)1e7

typedef void (*traverse_fn)(Bst *b, visit_fn fn);

int get_rand_value();
void fill_bst(Bst **b, int n);
int calc_mean(Bst *b);
int min_height(int n);
void display_node(Bst *b);
void do_nothing(Bst *b);
void time_execution(Bst *r, traverse_fn tr_fn, visit_fn vs_fn, char *message);

int main(int argc, char *argv[]) {
  srand(time(NULL));

  // create the root with a random value
  Bst *root = bst_new(get_rand_value());
  fill_bst(&root, AMOUNT_NODES);

  printf("amount nodes: %d\n\n", AMOUNT_NODES);

  // === Recursive ==
  printf("========= Recursive =========\n");
  time_execution(root, bst_rec_in_order, do_nothing, "rec_in_order: ");
  time_execution(root, bst_rec_pre_order, do_nothing, "rec_pre_order: ");
  time_execution(root, bst_rec_post_order, do_nothing, "rec_post_order: ");
  printf("\n");

  // === Iterative ==
  printf("========= Iterative =========\n");
  time_execution(root, bst_iter_in_order, do_nothing, "bst_iter_post_order");
  time_execution(root, bst_iter_pre_order, do_nothing, "iter_pre_order: ");
  time_execution(root, bst_iter_post_order, do_nothing, "iter_post_order: ");
  printf("\n");

  printf("========= Level order traversal =========\n");
  time_execution(root, level_order_traversal, do_nothing,
                 "level_order_traversal: ");

  // === Mean and min height ===
  printf("\n\n========= Mean & Min Height =========\n");
  printf("mean height: %d\n", calc_mean(root));
  printf("minimum height: %d\n", min_height(AMOUNT_NODES));

  bst_free(root);
}

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

void do_nothing(Bst *b) { return; }

void time_execution(Bst *r, traverse_fn tr_fn, visit_fn vs_fn, char *message) {
  printf("%s", message);
  clock_t start = clock();
  tr_fn(r, vs_fn);
  clock_t end = clock();

  double seconds = ((double)end - start) / CLOCKS_PER_SEC;
  printf("\ntook: %.5lf seconds\n\n", seconds);
}
