#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct list List;

List *list_create(size_t cap);
void list_mark(List *list);
void list_display(const List *const list);
void list_free(List *list);

#endif // !LIST_H
