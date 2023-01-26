#include <stdio.h>
#include <stdlib.h>
#include "../include/generic-red-black-tree.h"

int compare_int(void *a, void *b) {
  int *n1 = a;
  int *n2 = b;
  if (*n1 == *n2) return 0;
  return *n1 < *n2 ? -1 : 1;
}

void print_int(void *n) {
  printf("%d \n", *(int *)n);
}

int main (void) {
  GRBT *rbt = grbt_insert(NULL, &(int){1}, &(int){10}, compare_int);
  rbt = grbt_insert(rbt, &(int){2}, &(int){120}, compare_int);
  rbt = grbt_insert(rbt, &(int){3}, &(int){432}, compare_int);
  rbt = grbt_insert(rbt, &(int){4}, &(int){50}, compare_int);
  rbt = grbt_insert(rbt, &(int){0}, &(int){-1}, compare_int);

  grbt_print_in_order(rbt, print_int);
}
