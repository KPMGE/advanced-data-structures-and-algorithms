#ifndef STACK_H
#define  STACK_H
#include <stdbool.h>
#include "./bst.h"

typedef struct stack Stack;

Stack *stack_new();
void stack_push(Stack *s, Bst* b);
Stack *stack_pop(Stack *s);
void stack_free(Stack *s);
Bst *stack_get_tree(Stack *s);
bool stack_is_empty(Stack *s);

#endif