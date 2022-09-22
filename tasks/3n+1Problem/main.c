#include <stdio.h>

int function(int n) {
  int is_stopped = 0;
  while (!is_stopped) {
    printf("n: %d\n", n);
    if (n == 1) {
      is_stopped = 1;
    }
    if (n % 2 == 1) {
      n = 3 * n + 1;
    } else {
      n = n / 2;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  function(22);
  return 0;
}
