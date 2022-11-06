#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SWAP(A, B)                                                             \
  int aux = A;                                                                 \
  A = B;                                                                       \
  B = aux

#define PQ_CAP 200
int N = 0;
int pq[PQ_CAP];

bool less(int a, int b);
void pq_insert(int *pq, int k);
int pq_delmax(int *pq);
void fix_up(int *pq, int k);
void fix_down(int *pq, int size, int k);

int main(int argc, char *argv[]) {
  pq_insert(pq, 32);
  pq_insert(pq, 0);
  pq_insert(pq, 1);
  pq_insert(pq, 20);
  pq_insert(pq, 200);

  for (int i = 0; i < 5; i++) {
    printf("%d ", pq_delmax(pq));
  }
}

void pq_insert(int *pq, int k) {
  pq[++N] = k;
  fix_up(pq, N);
}

bool less(int a, int b) { return a < b; }

void fix_up(int *pq, int k) {
  // NOTE: pq[k/2] father of k
  while (k > 1 && less(pq[k / 2], pq[k])) {
    SWAP(pq[k / 2], pq[k]);
    k = k / 2;
  }
}

int pq_delmax(int *pq) {
  int max = pq[1];
  SWAP(pq[1], pq[N--]);
  fix_down(pq, N, 1);
  return max;
}

void fix_down(int *pq, int size, int k) {
  while (2 * k <= size) {
    // j holds the position of the kth child
    int j = 2 * k; 
    if (j < size && less(pq[j], pq[j + 1])) { j++; }
    if (!less(pq[k], pq[j])) break;
    SWAP(pq[k], pq[j]);
    k = j;
  }
}
