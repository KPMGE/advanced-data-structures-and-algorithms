#include <stdbool.h>
#include "item.h"
#include <stdlib.h>
#include <sys/time.h>

static int partition(Item *a, int lo, int hi) {
  int i = lo, j = hi + 1;
  // chose the pivot as the first element of the array.
  // we will be shuffle the array, as a consequence, chances are 
  // this element is gonna be a random one.
  Item pivot = a[lo];

  while (true) {
    // incremet i until the element at i is less than the pivot
    while(less(a[++i], pivot)) {
      if (i == hi) break;
    }
    // incremet decrement j until the pivot is smaller than a[j]
    while(less(pivot, a[--j])) {
      if (j == lo) break;
    }
    // checks if the elements have crossed
    if (i >= j) {
      break;
    }
    // swap elements
    swap(a[i], a[j]);
  }
  // the j position is actually the position where the pivot should be, so 
  // we put it there.
  swap(a[lo], a[j]);
  // return position of the pivot, element which is known to be in place.
  return j;
}

static void shuffle(Item *a, int N) {
  struct timeval tv; 
  gettimeofday(&tv, NULL);
  srand48(tv.tv_usec);
  for (int i = N-1; i > 0; i--) {
    int j = (unsigned int) (drand48()*(i+1));
    swap(a[i], a[j]);
  }
}

static void quick_sort(Item *a, int lo, int hi) {
  // if we pass arguments in the wrong order
  if (hi <= lo) return;
  // find the partition element position
  int j = partition(a, lo, hi);
  // recursivelly call the method for the subarray from lo to j -1
  quick_sort(a, lo, j - 1);
  // recursivelly call the method for the subarray from lo to j + 1 to hi
  quick_sort(a, j + 1, hi);
}


void sort(Item *a, int lo, int hi) {
  shuffle(a, hi-lo+1);
  quick_sort(a, lo, hi);
}
