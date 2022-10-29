#ifndef UF_H
#define UF_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct uf Uf;

// initializes the uf unit, with all elements disconnected
Uf* uf_new(size_t n);
// returns the id of elem
size_t uf_find(Uf *uf, size_t elem);
// checks if elem1 and elem2 are connected
bool uf_connected(Uf *uf, size_t elem1, size_t elem2);
// merge together elem1 and elem2
void uf_union(Uf *uf, size_t elem1, size_t elem2);
// free allocated memory for uf unit
void uf_free(Uf *uf);

#endif // !UF_H
