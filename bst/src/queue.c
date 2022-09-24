#include "../include/queue.h"
#include "../include/bst.h"
#include <stdlib.h>

typedef struct node {
  Bst *data;
  struct node *next;
} Node;

static Node *node_new(Bst *data) {
  Node *n = malloc(sizeof(Node));
  n->next = NULL;
  n->data = data;
  return n;
}

struct queue {
  Node *head;
  Node *tail;
};

Queue *queue_new() {
  Queue *q = malloc(sizeof(Queue));
  q->head = q->tail = NULL;
  return q;
}

void enqueue(Queue *q, Bst *data) {
  Node *new_node = node_new(data);

  if (!q->head) {
    q->head = q->tail = new_node;
    return;
  }

  q->tail->next = new_node;
  q->tail = new_node;
}

Bst *dequeue(Queue *q) {
  if (!q->tail || !q->head)
    return NULL;

  Node *aux = q->head;
  Bst *b = aux->data;
  q->head = aux->next;
  free(aux);

  return b;
}

void queue_free(Queue *q) {
  Node *curr = q->head;

  while (curr) {
    Node *aux = curr;
    curr = curr->next;
    free(aux);
  }

  free(q);
}

bool queue_is_empty(Queue *q) { return !q->head; }
