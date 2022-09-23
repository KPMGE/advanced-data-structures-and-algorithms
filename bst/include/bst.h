#ifndef BST_H
#define BST_H

typedef struct bst Bst;

Bst *bst_new();
void bst_add(Bst *b, int v);
void bst_free(Bst *b);
void bst_display(Bst *b);
int bst_height(Bst *b);

#endif // !BST_H
