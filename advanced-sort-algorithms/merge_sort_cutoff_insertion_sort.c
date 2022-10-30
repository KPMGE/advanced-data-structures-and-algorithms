#include "item.h"
#include <stdlib.h>

#define CUTOFF 4

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

static void merge_sort(Item *a, Item *aux, int lo, int hi) {
  // if we have just CUTOFF elements on the array, it's better to use a algorithm that works 
  // well for small arrays, just like insertion_sort.
  if (hi <= lo + CUTOFF - 1) {
    insertion_sort(a, lo, hi);
    return;
  }
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
