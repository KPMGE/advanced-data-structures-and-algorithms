#include "../include/list.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct list {
  size_t cap;
  char *elements;
};

static bool is_bit_on(char byte, size_t n) { return byte & (0x1 << n); }

static void mark_bit(List *list, int pos) {
  size_t post_byte = pos / 8;
  size_t pos_bit = pos % 8;

  list->elements[post_byte] = list->elements[post_byte] | (0x1 << pos_bit);
}

List *list_create(size_t cap) {
  size_t list_size = (cap / 8) + 1;
  List *l = malloc(sizeof(List));

  l->cap = cap;
  l->elements = malloc(sizeof(char) * list_size);

  return l;
}

void list_mark(List *list) {
  for (size_t i = 2; i < list->cap; i++) {
    for (size_t j = 2 * i; j < list->cap; j += i) {
      mark_bit(list, j);
    }
  }
}

void list_display(const List *const list) {
  for (size_t i = 0; i < list->cap; i++) {
    size_t post_byte = i / 8;
    size_t pos_bit = i % 8;

    char byte = list->elements[post_byte];

    if (is_bit_on(byte, pos_bit))
      continue;

    printf("%zu ", i);
  }
}

void list_free(List *list) {
  free(list->elements);
  free(list);
}
