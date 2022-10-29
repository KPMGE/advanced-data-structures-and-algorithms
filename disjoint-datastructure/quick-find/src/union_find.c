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

size_t uf_find(Uf *uf, size_t elem) {
  assert(elem < uf->size && "Invalid element position");
  return uf->ids[elem];
}

bool uf_connected(Uf *uf, size_t elem1, size_t elem2) {
  return uf_find(uf, elem1) == uf_find(uf, elem2);
}

void uf_union(Uf *uf, size_t elem1, size_t elem2) {
  size_t id_elem1 = uf_find(uf, elem1);
  size_t id_elem2 = uf_find(uf, elem2);
  for (size_t i = 0; i < uf->size; i++) {
    if (uf->ids[i] == id_elem1) {
      uf->ids[i] = id_elem2;
    }
  }
}

void uf_free(Uf *uf) {
  free(uf->ids);
  free(uf);
}
