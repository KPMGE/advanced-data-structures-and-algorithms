#include "../include/stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluate_expression(const char *op, Stack *operators, Stack *numbers);

int calculate_expression(char *expression, Stack *operators, Stack *numbers);

int main(int argc, char *argv[]) {
  char *expression = strdup("( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )");

  Stack *operators = stack_new();
  Stack *numbers = stack_new();

  int result = calculate_expression(expression, operators, numbers);
  printf("result: %d", result);
}

int evaluate_expression(const char *op, Stack *operators, Stack *numbers) {
  int fnum = *((int *)pop(numbers));
  int snum = *((int *)pop(numbers));

  if (!strcmp(op, "+")) {
    return fnum + snum;
  }
  if (!strcmp(op, "*")) {
    return fnum * snum;
  }
  if (!strcmp(op, "-")) {
    return fnum - snum;
  }
  printf("operation not defined!");
  exit(1);
}

int calculate_expression(char *expression, Stack *operators, Stack *numbers) {
  char *token = strtok(expression, " ");

  while (token != NULL) {
    token = strtok(NULL, " ");

    // end of expression
    if (!token)
      break;

    // skip
    if (!strcmp(token, "("))
      continue;

    // calculate expression
    if (!strcmp(token, ")")) {
      char *op = (char *)pop(operators);
      int result = evaluate_expression(op, operators, numbers);
      int *num_ptr = malloc(sizeof(int));
      *num_ptr = result;
      push(numbers, num_ptr);
      continue;
    }

    // add to the operators stack
    if (!strcmp(token, "+") || !strcmp(token, "-") || !strcmp(token, "*")) {
      push(operators, token);
      continue;
    }

    // add to the numbers stack
    int *num_ptr = malloc(sizeof(int));
    *num_ptr = atoi(token);
    push(numbers, num_ptr);
  }

  return *((int *)pop(numbers));
}
