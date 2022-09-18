// version with static vector of ints

#include <stdint.h>
#include <stdio.h>
#define CAP 100000

int elements[CAP];

void mark() {
  for (int i = 2; i < CAP; i++) {
    for (int j = 2 * i; j < CAP; j += i) {
      elements[j] = -1;
    }
  }
}

void display() {
  for (int i = 2; i < CAP; i++) {
    if (elements[i] == -1) {
      continue;
    }
    printf("%d ", i);
  }
}

int main(void) {
  mark();
  display();
}
