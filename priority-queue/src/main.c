#include <stdio.h>
#include <stdlib.h>
#include "../include/priority_queue.h"

int main (int argc, char *argv[]) {
  PriorityQueue *pq = priority_queue_new(10);
  priority_queue_insert(pq, 10);
  priority_queue_insert(pq, 20);
  priority_queue_insert(pq, 0);
  priority_queue_insert(pq, 100);

  printf("%d", priority_queue_delete_max(pq));
  printf("%d", priority_queue_delete_max(pq));
  printf("%d", priority_queue_delete_max(pq));

  priority_queue_free(pq);
}
