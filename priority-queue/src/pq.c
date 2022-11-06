#include "../include/pq.h"
#include <stdlib.h>

#define SWAP(type, a, b)                                                       \
  {                                                                            \
    type temp = a;                                                             \
    a = b;                                                                     \
    b = temp;                                                                  \
  }

struct pq {
  int n;
  int *queue;
};

static int less(int a, int b) {
  return a < b;
}

static void fix_down(Pq *pq, int k, compare_func fn) {
  int *a = pq->queue;
  while(2 * k <= pq->n) {
    int j = 2 * k;
    if (j < pq->n && fn(a[j], a[j + 1])) j++;
    if (!fn(a[k], a[j])) break;
    SWAP(int, a[k], a[j]);
    k = j;
  }
}

static void fix_up(Pq *pq, int k, compare_func fn) {
  while (k > 1 && fn(pq->queue[k], pq->queue[k/2])) {
    SWAP(int, pq->queue[k], pq->queue[k/2]);
    k = k / 2;
  }
}

Pq *pq_new(int size) {
  Pq *pq = malloc(sizeof(Pq));
  pq->queue = malloc(sizeof(int) * size);
  pq->n = 0;
  return pq;
}

void pq_insert(Pq *pq, int k) {
  pq->queue[++pq->n] = k;
  fix_up(pq, pq->n, less);
}

int pq_delete_max(Pq *pq) {
  int max = pq->queue[1];
  SWAP(int, pq->queue[1], pq->queue[pq->n--]);
  fix_down(pq, 1, less);
  return max;
}

void pq_free(Pq *pq) {
  free(pq->queue);
  free(pq);
}
