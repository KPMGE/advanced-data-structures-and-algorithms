#include "../include/union_find.h"
#include <assert.h>

struct uf {
  size_t *ids;
  size_t size;
  size_t *sizes;
};

Uf* uf_new(size_t n) {
  Uf *uf = malloc(sizeof(Uf));
  uf->size = n;
  uf->ids = malloc(sizeof(size_t) * n);
  uf->sizes = malloc(sizeof(size_t) * n);

  for (size_t i = 0; i < n; i++) {
    uf->sizes[i] = 1; 
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

  // if size of connected component of elem1 is smaller, it should be the child
  if (uf->sizes[root1] < uf->sizes[root2]) {
    uf->ids[root1] = root2;
    uf->sizes[root2] += uf->sizes[root1];
  } else {
    uf->ids[root2] = root1;
    uf->sizes[root1] += uf->sizes[root2];
  }
}

void uf_free(Uf *uf) {
  free(uf->sizes);
  free(uf->ids);
  free(uf);
}
