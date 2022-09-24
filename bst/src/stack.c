#include "../include/stack.h"
#include <stdlib.h>

typedef struct node {
  Bst *data;
  struct node *next;
} Node;

struct stack {
  Node *head;
};

Node *node_new(Bst *data) {
  Node *n = malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;
  return n;
}

Stack *stack_new() {
  Stack *s = malloc(sizeof(Stack));
  s->head = NULL;
  return s;
}

void stack_push(Stack *s, Bst *b) {
  Node *new_node = node_new(b);

  if (!s) {
    s->head = new_node;
    return;
  }

  new_node->next = s->head;
  s->head = new_node;
}

bool stack_is_empty(Stack *s) { return !s->head; }

Bst *stack_peek(Stack *s) { return s->head->data; }

Bst *stack_pop(Stack *s) {
  if (!s || stack_is_empty(s))
    return NULL;

  Node *aux = s->head;
  Bst *tree = aux->data;
  s->head = aux->next;
  free(aux);

  return tree;
}

void stack_free(Stack *s) {
  Node *curr = s->head;

  while (curr) {
    Node *aux = curr;
    curr = curr->next;
    free(aux);
  }
  free(s);
}
