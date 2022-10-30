// NOTE: bubble sort is kinda like insertion sort, but we need to always walk through 
// the entire vector. Basically, we do that till there is no unsorted element on the vector.

#include "item.h"
#include <stdbool.h>

void sort(Item *a, int lo, int hi) {
  bool swapped = false;
  for (int i = lo; i < hi; i++) {
    for (int j = hi; j > 0; j--) {
      if (a[j] < a[j -1]) {
        swap(a[j], a[j - 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}
