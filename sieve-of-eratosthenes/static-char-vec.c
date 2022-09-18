// version with static vector of ints

#include <stdint.h>
#include <stdio.h>
#define CAP 100000

char elements[CAP];

void mark() {
  for (int i = 2; i < CAP; i++) {
    for (int j = 2 * i; j < CAP; j += i) {
      elements[j] = 'x';
    }
  }
}

void display() {
  for (int i = 2; i < CAP; i++) {
    if (elements[i] == 'x') {
      continue;
    }
    printf("%d ", i);
  }
}

int main(void) {
  mark();
  display();
}
