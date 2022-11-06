#ifndef PQ_H
#define PQ_H

typedef struct pq Pq;
typedef int (*compare_func)(int a, int b);

Pq *pq_new(int size);
void pq_insert(Pq *pq, int k);
int pq_delete_max(Pq *pq);
void pq_free(Pq *pq);

#endif // !PQ_Q
