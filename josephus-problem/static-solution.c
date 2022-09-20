// reference:
// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/#:~:text=In%20computer%20science%20and%20mathematics,circle%20in%20a%20fixed%20direction.

#include <stdio.h>
#define N 9

char people[N];

int Josephus(int m) {
  // adjusts the start of the group
  m--;
  // Cut = 0 gives the sword to 1st person.
  int cnt = 0, cut = 0, num = 1;
  // Loop continues till n-1 person dies.
  while (cnt < (N - 1)) {
    // Checks next (kth) alive persons.
    while (num <= m) {
      cut++;
      // Checks and resolves overflow
      // of Index.
      cut = cut % N;
      if (!people[cut]) {
        // Updates the number of persons
        // alive.
        num++;
      }
    }
    // prints the current number
    printf("%d ", cut + 1);
    // Refreshes value to 1 for next use.
    num = 1;
    // Kills the person at position of 'cut'
    people[cut] = 'x';
    // Updates the no. of killed persons.
    cnt++;
    cut++;
    // Checks and resolves overflow of Index.
    cut = cut % N;
    // Checks the next alive person the
    // sword is to be given.
    while (people[cut] == 'x') {
      cut++;
      // Checks and resolves overflow
      // of Index.
      cut = cut % N;
    }
  }
  // Output is the position of the last
  // man alive(Index + 1);
  return cut + 1;
}

// Driver code
int main() {
  int m = 5;
  printf("%d", Josephus(m));
}
