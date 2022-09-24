#include "../include/bst.h"
#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))

struct bst {
  int value;
  Bst *left;
  Bst *right;
};

Bst *bst_new(int v) {
  Bst *b = malloc(sizeof(Bst));
  b->left = b->right = NULL;
  b->value = v;
  return b;
}

int bst_get_value(Bst *b) { return b->value; }

Bst *bst_add(Bst *b, int v) {
  if (!b)
    return bst_new(v);
  if (v < b->value)
    b->left = bst_add(b->left, v);
  if (v > b->value)
    b->right = bst_add(b->right, v);
  return b;
}

void bst_free(Bst *b) {
  if (b) {
    bst_free(b->left);
    bst_free(b->right);
    free(b);
  }
}

int bst_height(Bst *b) {
  if (!b)
    return -1;
  int left_height = bst_height(b->left);
  int right_height = bst_height(b->right);
  return MAX(left_height, right_height) + 1;
}

void bst_rec_pre_order(Bst *b, visit_fn fn) {
  if (!b)
    return;
  fn(b);
  bst_rec_in_order(b->left, fn);
  bst_rec_in_order(b->right, fn);
}

void bst_rec_in_order(Bst *b, visit_fn fn) {
  if (!b)
    return;
  bst_rec_in_order(b->left, fn);
  fn(b);
  bst_rec_in_order(b->right, fn);
}

void bst_rec_post_order(Bst *b, visit_fn fn) {
  if (!b)
    return;
  bst_rec_in_order(b->left, fn);
  bst_rec_in_order(b->right, fn);
  fn(b);
}

void bst_iter_pre_order(Bst *b, visit_fn fn) {
  if (!b)
    return;

  Stack *s = stack_new();
  stack_push(s, b);

  while (!stack_is_empty(s)) {
    b = stack_pop(s);
    fn(b);
    if (b->right) {
      stack_push(s, b->right);
    }
    if (b->left) {
      stack_push(s, b->left);
    }
  }

  stack_free(s);
}

void bst_iter_in_order(Bst *b, visit_fn fn) {
  Stack *s = stack_new();

  while (!stack_is_empty(s) || b) {
    if (b) {
      stack_push(s, b);
      b = b->left;
    } else {
      b = stack_pop(s);
      fn(b);
      b = b->right;
    }
  }

  stack_free(s);
}

void bst_iter_post_order(Bst *b, visit_fn fn) {
  Stack *s = stack_new();
  Bst *last_visited_node = NULL;

  while (!stack_is_empty(s) || b) {
    if (b) {
      stack_push(s, b);
      b = b->left;
    } else {
      Bst *peek_node = stack_peek(s);
      if (peek_node->right && (last_visited_node != peek_node->right)) {
        b = peek_node->right;
      } else {
        fn(peek_node);
        last_visited_node = stack_pop(s);
      }
    }
  }

  stack_free(s);
}
