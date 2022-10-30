#include "item.h"
#include <stdlib.h>

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

static void merge_sort(Item *a, Item *aux, int lo, int hi) {
  // if we pass in the arguments in a wrong order, just skip
  if (hi <= lo) return;
  // find the middle of the array
  int mid = lo + (hi - lo) / 2;
  // call the algorithm recursively for the left-half array
  merge_sort(a, aux, lo, mid);
  // call the algorithm recursively for the right-half array
  merge_sort(a, aux, mid + 1, hi);
  // merge the sorted arrays together
  merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi) {
  // allocate the auxiliary array.
  int n = (hi - lo) + 1;
  int *aux = malloc(sizeof(int) * n);
  merge_sort(a, aux, lo, hi);
  free(aux);
}
