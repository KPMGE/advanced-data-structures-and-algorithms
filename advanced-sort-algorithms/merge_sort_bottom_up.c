#include "item.h"
#include <stdlib.h>

#define SZ2 (sz+sz)
#define MIN(A, B) ((A < B) ? (A) : (B))

static void merge(Item *a, Item *aux, int lo, int mid, int hi) {
  // copy contents from a to aux
  for (int i = lo; i <= hi; i++) {
    aux[i] = a[i];
  }

  // do the merge
  // NOTE: i is the index of the left half array, j is the index of the right
  // half array
  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    // if i > mid, we know that the left-half array has been completely contumed, so we just add the remaining 
    // elements from the right-half array.
    if (i > mid) {
      a[k] = aux[j++];
      continue;
    }
    // if j > hi, we know that the right-half array has been completely contumed, so we just add the remaining 
    // elements from the left-half array.
    if (j > hi) {
      a[k] = aux[i++];
      continue;
    }
    // if the element of the let-half array is smaller than the element on the right-half array, we add it to the 
    // original array.
    if (less(aux[i], aux[j])) {
      a[k] = aux[i++];
      continue;
    }
    // otherwise, we add the element of the right-half array
    a[k] = aux[j++];
  }
}

void insertion_sort(Item *a, int lo, int hi) {
  // walks through all elements starting from 1
  for (int i = lo + 1; i < hi; i++) {
    // look at the elements starting from i. Swap them if necessary. Stop if the 
    // position reaches the minimum or if the a[k] elemens has no smaller elements. In this case, 
    // as the elements are sorted, we know for sure that there are no remaning elements that are 
    // smaller than a[k] anyways.
    for (int k = i; k > 0 && a[k] < a[k - 1]; k--) {
      // swap a[k] with a[k - 1], cuz a[k] is smaller in this case
      swap(a[k], a[k - 1]);
    }
  }
}

void sort(Item *a, int lo, int hi) {
  // allocate the auxiliary array.
  int n = (hi - lo) + 1;
  int y = n - 1;
  Item *aux = malloc(sizeof(Item) * n);

  for (int sz = 1; sz < n; sz = SZ2) {
    for (int lo = 0; lo < n - sz; lo += SZ2) {
      int x = lo + SZ2 - 1;
      merge(a, aux, lo, lo + sz - 1, MIN(x, y));
    }
  }

  free(aux);
}
