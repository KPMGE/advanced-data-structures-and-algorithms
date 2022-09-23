#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} Node;

static Node *node_new(int v) {
  Node *n = malloc(sizeof(Node));
  n->left = n->right = NULL;
  n->value = v;
  return n;
}

static Node *node_add(Node *n, int v) {
  if (!n)
    return node_new(v);
  if (n->value < v)
    n->left = node_add(n->left, v);
  if (n->value > v)
    n->right = node_add(n->right, v);
  return n;
}

static void display(Node *n) {
  if (!n) {
    return;
  }
  printf("%d\n", n->value);
  display(n->left);
  display(n->right);
}

static void free_nodes(Node *n) {
  if (n) {
    free_nodes(n->left);
    free_nodes(n->right);
    free(n);
  }
}

static int height(Node *n) {
  if (!n)
    return 0;
  int left_height = height(n->left);
  int right_height = height(n->right);
  return MAX(left_height, right_height) + 1;
}

struct bst {
  Node *root;
};

Bst *bst_new() {
  Bst *b = malloc(sizeof(Bst));
  b->root = NULL;
  return b;
}

void bst_add(Bst *b, int v) { b->root = node_add(b->root, v); }

void bst_free(Bst *b) {
  free_nodes(b->root);
  free(b);
}

// Find height of a tree, defined by the root node
int bst_height(Bst *b) { return height(b->root); }

void bst_display(Bst *b) { display(b->root); }
