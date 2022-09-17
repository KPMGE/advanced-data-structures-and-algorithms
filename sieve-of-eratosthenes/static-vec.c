// version with static vector

#include <stdint.h>
#include <stdio.h>
#define CAP 100

char elements[CAP / 8 + 1];

void mark_position(int pos) {
  int post_byte = pos / 8;
  int pos_bit = pos % 8;

  elements[post_byte] = elements[post_byte] | (0x1 << pos_bit);
}

void mark() {
  for (int i = 2; i < CAP; i++) {
    for (int j = 2 * i; j < CAP; j += i) {
      mark_position(j);
    }
  }
}

void display() {
  for (int i = 2; i < CAP; i++) {
    int post_byte = i / 8;
    int pos_bit = i % 8;
    if (elements[post_byte] & (0x1 << pos_bit)) {
      continue;
    }
    printf("%d ", i);
  }
}

int main(void) {
  mark();
  display();
}
