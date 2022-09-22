#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int function(int n) {
  int res = 0;
  int is_stopped = 0;
  while (!is_stopped) {
    ++res;
    /*printf("n: %d\n", n);*/
    if (n == 1) {
      is_stopped = 1;
    }
    if (n % 2 == 1) {
      n = 3 * n + 1;
    } else {
      n = n / 2;
    }
  }
  return res;
}

int main(int argc, char const *argv[]) {
  int k;
  int j;
  while (scanf("%d %d\n", &k, &j) == 2) {
    if (k < 0 || k > 1000000 || j < 0 || j > 1000000) {
      exit(EXIT_FAILURE);
    }
    printf("%d %d", k, j); // errors
    if (j < k) {
      int tmp = k;
      k = j;
      j = k;
    }
    int glob = 0;
    for (int i = k; i <= j; ++i) {
      int out = function(i);
      if (out > glob)
        glob = out;
    }
    printf(" %d\n", glob);
  }
  return 0;
}
