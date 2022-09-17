#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  size_t list_size = 0;

  printf("enter list size: ");
  scanf("%zu", &list_size);

  List *l = list_create(list_size);

  list_mark(l);

  printf("Prime number till %zu: \n", list_size);
  list_display(l);
  printf("\n");

  list_free(l);
}
