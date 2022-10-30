#ifndef ITEM_H
#define ITEM_H

// interface for all sort algorithms
typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define swap(A, B) { Item t = A; A = B; B = t; }
#define compswap(A, B) if (less(B, A)) exch(A, B)

#endif // !ITEM_H
