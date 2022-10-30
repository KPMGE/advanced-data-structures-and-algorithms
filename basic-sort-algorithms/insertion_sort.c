// NOTE: The insertion sort algorithm is not so good when the array is reversed, buz when the array is nearly sorted
// and there are just a few elements, it works pretty well. The big point in here is that, it is a adaptive algorithm, 
// in other words, the time it takes to sort the array depends on how the array is arranged.

// NOTE: Although the IS algorithm is not used for big size arrays, usually is is part of bigger, divide and conquer algorithms, 
// like merge sort and quick sort, cuz it is a stable algorithm that works fine for small arrays.

#include "item.h"

void sort(Item *a, int lo, int hi) {
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
