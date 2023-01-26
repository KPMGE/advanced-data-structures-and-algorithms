#ifndef GRBT_H
#define GRBT_H

#include <stdbool.h>

typedef struct grbt GRBT;

typedef int (*compare_fn)(void *key1, void *key2);
typedef void (*print_fn)(void *);

GRBT *grbt_insert(GRBT *root, void *key, void *value, compare_fn cmp);
void *grbt_data(GRBT *node);
void grbt_print_in_order(GRBT *root, print_fn fn);

#endif // !GRBT_H
