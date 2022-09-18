// version with static bit vector

#include <stdint.h>
#include <stdio.h>
#define CAP 100

char elements[CAP / 8 + 1];

void mark_position(int pos) {
  // position of the byte that containt the bit pos
  int post_byte = pos / 8;
  // position of the bit within the byte
  int pos_bit = pos % 8;

  // turn on the bit on position pos
  elements[post_byte] = elements[post_byte] | (0x1 << pos_bit);
}

void mark() {
  // start from 2, the first prime number
  for (int i = 2; i < CAP; i++) {
    // mark all multiples of i
    for (int j = 2 * i; j < CAP; j += i) {
      // mark the bit in the position j
      mark_position(j);
    }
  }
}

void display() {
  for (int i = 2; i < CAP; i++) {
    // position of the byte that containt the bit i
    int post_byte = i / 8;
    // position of the bit within the byte
    int pos_bit = i % 8;

    // if the bit on the position i is marked, skip it because it's not a prime
    // number
    if (elements[post_byte] & (0x1 << pos_bit)) {
      continue;
    }

    // display prime number
    printf("%d ", i);
  }
}

int main(void) {
  mark();
  display();
}
