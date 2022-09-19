#include "../include/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void *data;
  struct node *next;
} Node;

Node *new_node(void *data) {
  Node *new = malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;
  return new;
}

struct stack {
  Node *top;
  size_t size;
};

static bool is_empty(Stack *s) { return !s->size; }

Stack *stack_new() {
  Stack *s = malloc(sizeof(Stack));
  s->size = 0;
  s->top = NULL;
  return s;
}

void *pop(Stack *s) {
  if (is_empty(s)) {
    printf("stack empty!!");
    return NULL;
  }

  void *data = s->top->data;
  s->size--;
  Node *aux = s->top;
  s->top = aux->next;
  free(aux);

  return data;
}

void push(Stack *s, void *data) {
  Node *nd = new_node(data);

  if (is_empty(s)) {
    s->size++;
    s->top = nd;
    return;
  }

  s->size++;
  nd->next = s->top;
  s->top = nd;
}

size_t stack_size(Stack *s) { return s->size; }

void stack_free(Stack *s) {
  for (int i = 0; i < s->size; i++) {
    pop(s);
  }
}
