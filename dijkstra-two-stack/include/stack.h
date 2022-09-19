#ifndef STACK_H
#define STACK_H

#include <stddef.h>
typedef struct stack Stack;

Stack *stack_new();
void *pop(Stack *s);
void push(Stack *s, void *data);
size_t stack_size(Stack *s);
void stack_free(Stack *s);

#endif // !STACK_H
