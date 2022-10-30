#include "item.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// extern function to be replaced with each sort algorithm
extern void sort(Item *a, int lo, int hi);

int *array_new(int n);
void array_display(int *array, int n);
void array_read(const char *file_path, int *array, int size);

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("usage: ./executable <path to file> <number of elemts>");
    exit(1);
  }

  const char* file_path = argv[1];
  const int array_size = atoi(argv[2]);
  int *array = array_new(array_size);
  array_read(file_path, array, array_size);

  clock_t start = clock();
  sort(array, 0, array_size - 1);
  clock_t end = clock();
  printf("time spent: %.3f", ((double)(end - start)) / CLOCKS_PER_SEC);

  // array_display(array, array_size);

  free(array);
}

int *array_new(int n) { return malloc(sizeof(int) * n); }

void array_read(const char *file_path, int *array, int size) {
  FILE *f = fopen(file_path, "r");
  assert(f != NULL && "Error when opening file");

  for (int i = 0; i < size; i++) {
    fscanf(f, "%d", &array[i]);
  }

  fclose(f);
}

void array_display(int *array, int n) {
  for (int i = 0; i < n; i++) {
    if (i % 5 == 0) {
      printf("\n");
    }
    printf(" %d ", array[i]);
  }
}
