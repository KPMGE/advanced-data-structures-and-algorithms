#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/union_find.h"

int main (int argc, char *argv[]) {
  assert(argc > 1 && "No arguments provided!");
  size_t amount_elems = atoi(argv[1]);

  Uf *uf = uf_new(amount_elems);

  size_t elem1, elem2;
  for (size_t i = 0; i < amount_elems; i++) {
    scanf("%zu %zu", &elem1, &elem2);
    if (!uf_connected(uf, elem1, elem2)) {
      uf_union(uf, elem1, elem2);
      printf("%zu and %zu are not yet connected, connecting them...\n", elem1, elem2);
      continue;
    }
    printf("%zu and %zu are already connected, skipping them...\n", elem1, elem2);
  } 

  uf_free(uf);
}
