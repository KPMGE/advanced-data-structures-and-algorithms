#ifndef QUEUE_H
#define QUEUE_H

#include "../include/bst.h"
#include <stdbool.h>

typedef struct queue Queue;

Queue *queue_new();
void enqueue(Queue *q, Bst *data);
Bst *dequeue(Queue *q);
void queue_free(Queue *q);
bool queue_is_empty(Queue *q);

#endif // !QUEUE_H
