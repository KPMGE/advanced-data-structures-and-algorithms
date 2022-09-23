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

int bst_get_value(Bst *b) {
  return b->value;
}

Bst *bst_add(Bst *b, int v) {
  if (!b)
    return bst_new(v);
  if (b->value < v)
    b->left = bst_add(b->left, v);
  if (b->value > v)
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

void bst_rec_in_order(Bst *b, visit_fn fn) {
	if (!b) return;
	bst_rec_in_order(b->left, fn);
	fn(b);
	bst_rec_in_order(b->right, fn);
}

void bst_rec_pre_order(Bst *b, visit_fn fn) {
	if (!b) return;
	fn(b);
	bst_rec_in_order(b->left, fn);
	bst_rec_in_order(b->right, fn);
}

void bst_rec_post_order(Bst *b, visit_fn fn) {
	if (!b) return;
	bst_rec_in_order(b->left, fn);
	bst_rec_in_order(b->right, fn);
	fn(b);
}

// procedure iterativePreorder(node)
//     if node = null
//         return
//     stack ← empty stack
//     stack.push(node)
//     while not stack.isEmpty()
//         node ← stack.pop()
//         visit(node)
//         // right child is pushed first so that left is processed first
//         if node.right ≠ null
//             stack.push(node.right)
//         if node.left ≠ null
//             stack.push(node.left

void bst_iter_in_order(Bst *b, visit_fn fn) {
  if (!b) return;

  Stack *s = stack_new();
  stack_push(s, b);

  while (!stack_is_empty(s)) {
    Bst *node = stack_get_tree(stack_pop(s));
    fn(node);
    if (node->right) {
      stack_push(s, node->right);
    }
    if (node->left) {
      stack_push(s, node->left);
    }
  }
}

void bst_iter_pre_order(Bst *b, visit_fn fn) {
  printf("NOT IMPLEMENTED: bst_iter_pre_order");
}

void bst_iter_post_order(Bst *b, visit_fn fn) {
  printf("NOT IMPLEMENTED: bst_iter_post_order");
}