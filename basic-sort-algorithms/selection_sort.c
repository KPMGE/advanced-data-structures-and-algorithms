#include "item.h"

void sort(Item *a, int lo, int hi) {
  int k = 0;
  for (int i = lo; i < hi; i++) {
    // index of the smallest value index from i.
    k = i;
    // finds the smallest value index
    for (int j = (i + 1); j < hi; j++) {
      // if the value of a[j] is smaller than a[k], we update k
      if (a[j] < a[k]) {
        k = j;
      }
    }
    // swap the smallest element with the current ith element.
    swap(a[i], a[k]);
  }
}
