#include <stdio.h>

int main(int argc, char const *argv[]) {
  int central_point = 6;
  int end_point = 8;
  while (1) {
    if (2 * central_point * central_point ==
        end_point + end_point * end_point) {
      printf("Find solution %d %d\n", central_point, end_point);
    }
    // TODO: need to compare and add number increasing
  }
  return 0;
}
