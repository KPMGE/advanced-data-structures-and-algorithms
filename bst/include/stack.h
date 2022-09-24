#ifndef STACK_H
#define STACK_H
#include "./bst.h"
#include <stdbool.h>

typedef struct stack Stack;

Stack *stack_new();
void stack_push(Stack *s, Bst *b);
Bst *stack_pop(Stack *s);
Bst *stack_peek(Stack *s);
void stack_free(Stack *s);
bool stack_is_empty(Stack *s);

#endif
