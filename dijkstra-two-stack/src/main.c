#include "../include/stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double evaluate_expression(const char *op, Stack *operators, Stack *numbers);
double calculate_expression(char *expression, Stack *operators, Stack *numbers);
char *pop_char(Stack *s);
double pop_double(Stack *s);
void push_double(Stack *s, double num);

int main(int argc, char *argv[]) {
  char *expression = strdup("( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )");

  Stack *operators = stack_new();
  Stack *numbers = stack_new();

  double result = calculate_expression(expression, operators, numbers);
  printf("result: %.2lf", result);

  stack_free(numbers);
  stack_free(operators);
}

char *pop_char(Stack *s) { return (char *)pop(s); }
double pop_double(Stack *s) { return *((double *)pop(s)); }
void push_double(Stack *s, double num) {
  double *num_ptr = malloc(sizeof(double));
  *num_ptr = num;
  push(s, num_ptr);
}

double evaluate_expression(const char *op, Stack *operators, Stack *numbers) {
  double fnum = pop_double(numbers);
  double snum = pop_double(numbers);

  if (!strcmp(op, "+"))
    return fnum + snum;
  if (!strcmp(op, "*"))
    return fnum * snum;
  if (!strcmp(op, "-"))
    return fnum - snum;
  if (!strcmp(op, "/"))
    return fnum / snum;
  printf("operation not defined!");
  exit(1);
}

double calculate_expression(char *expression, Stack *operators,
                            Stack *numbers) {
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
      char *op = pop_char(operators);
      double result = evaluate_expression(op, operators, numbers);
      push_double(numbers, result);
      continue;
    }

    // add to the operators stack
    if (!strcmp(token, "+") || !strcmp(token, "-") || !strcmp(token, "*") ||
        !strcmp(token, "/")) {
      push(operators, token);
      continue;
    }

    // add to the numbers stack
    double num = atoi(token);
    push_double(numbers, num);
  }

  return pop_double(numbers);
}
