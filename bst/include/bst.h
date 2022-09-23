#ifndef BST_H
#define BST_H

typedef struct bst Bst;
typedef void (*visit_fn)(Bst *b);

Bst *bst_new(int v);
Bst *bst_add(Bst *b, int v);
void bst_free(Bst *b);
void bst_display(Bst *b);
int bst_height(Bst *b);
void bst_rec_in_order(Bst *b, visit_fn fn);
void bst_rec_pre_order(Bst *b, visit_fn fn);
void bst_rec_post_order(Bst *b, visit_fn fn);
void bst_iter_in_order(Bst *b, visit_fn fn);
void bst_iter_pre_order(Bst *b, visit_fn fn);
void bst_iter_post_order(Bst *b, visit_fn fn);
int bst_get_value(Bst *b);

#endif // !BST_H
