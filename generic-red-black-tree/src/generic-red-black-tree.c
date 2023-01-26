#include "../include/generic-red-black-tree.h"
#include <stdlib.h>

#define BLACK false
#define RED   true

struct grbt {
  void *key;
  void *data;
  bool color;
  GRBT *left;
  GRBT *right;
};

static bool is_red(GRBT *node);
static GRBT *rotate_left(GRBT *current_root);
static GRBT *rotate_right(GRBT *current_root);
static void flip_colors(GRBT *node);
static GRBT *make_node(void *key, void *data, bool color);

GRBT *grbt_insert(GRBT *root, void *key, void *data, compare_fn cmp) {
  // insert at leaf and color the edge to red
  if (!root) return make_node(key, data, RED);

  int result_comp = cmp(key, root->key);
  if (result_comp < 0) {
    root->left = grbt_insert(root->left, key, data, cmp);
  } else if (result_comp > 0) {
    root->right = grbt_insert(root->right, key, data, cmp);
  } else {
    root->data = data;
  }

  if (is_red(root->right) && !is_red(root->left)) {
    root = rotate_left(root);
  }
  if (is_red(root->left) && is_red(root->left->left)) {
    root = rotate_right(root);
  }
  if (is_red(root->left) && is_red(root->right)) {
    flip_colors(root);
  }

  return root;
}

void *grbt_search(GRBT *root, void *key, compare_fn cmp) {
  if (!root) return NULL;

  int result_comp = cmp(root->key, key);
  if (result_comp < 0) {
    return grbt_search(root, key, cmp);
  } else if (result_comp > 0) {
    return grbt_search(root, key, cmp);
  } 

  return root->data;
}

void *grbt_data(GRBT *node) {
  return node->data;
}

void grbt_print_in_order(GRBT *root, print_fn fn) {
  if (root) {
    grbt_print_in_order(root->left, fn);
    fn(root->data);
    grbt_print_in_order(root->right, fn);
  }
}

static bool is_red(GRBT *node) {
  if (!node) return BLACK;
  return node->color;
}

static GRBT *rotate_left(GRBT *current_root) {
  GRBT *new_root = current_root->right;

  current_root->right = new_root->left;
  new_root->left = current_root;
  new_root->color = new_root->left->color;
  new_root->left->color = RED;

  return new_root;
}

static GRBT *rotate_right(GRBT *current_root) {
  GRBT *new_root = current_root->left;

  current_root->left = current_root->right;
  new_root->right = current_root;
  new_root->color = new_root->right->color;
  new_root->right->color = RED;

  return new_root;
}

static void flip_colors(GRBT *node) {
  node->color = RED;
  node->right->color = BLACK;
  node->left->color = BLACK;
}

static GRBT *make_node(void *key, void *data, bool color) {
  GRBT *new = malloc(sizeof(GRBT));

  new->key = key;
  new->data = data;
  new->color= color;

  return new;
}
