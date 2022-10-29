#include "../include/union_find.h"
#include <assert.h>

struct uf {
  size_t *ids;
  size_t size;
};

Uf* uf_new(size_t n) {
  Uf *uf = malloc(sizeof(Uf));
  uf->size = n;
  uf->ids = malloc(sizeof(size_t) * n);

  for (size_t i = 0; i < n; i++) {
    uf->ids[i] = i;
  }

  return uf;
}

size_t uf_find(Uf *uf, size_t pos) {
  assert(pos < uf->size && "Invalid element position");
  // find the father of pos
  while(uf->ids[pos] != pos) pos = uf->ids[pos];
  return pos;
}

bool uf_connected(Uf *uf, size_t elem1, size_t elem2) {
  // id elem1 and elem2 have the same root, they're at the same connected component
  return uf_find(uf, elem1) == uf_find(uf, elem2);
}

void uf_union(Uf *uf, size_t elem1, size_t elem2) {
  // find roots for elem1 and elem2
  size_t root1 = uf_find(uf, elem1);
  size_t root2 = uf_find(uf, elem2);
  // if the elements are already connected, skip
  if (root1 == root2) return;
  // connected component of elem1 is child of connected component of elem2
  uf->ids[root1] = root2;
}