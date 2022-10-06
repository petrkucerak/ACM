#include <stdio.h>
#include <stdlib.h>

void print_data(int *data, int boxes, int dimesnion);

int main(int argc, char const *argv[]) {
  printf("Stacking Boxes!\n");

  int status = 1;
  int *data = NULL;

  // load a data
  while (status) {
    int boxes, dimesnion;
    if (scanf("%d %d\n", &boxes, &dimesnion) != 2) {
      // end of the program
      exit(EXIT_SUCCESS);
    }

    printf("\n");
    printf("Loaded input: %d boxes, %d dimension.\n", boxes, dimesnion);
    data = malloc(sizeof(int) * boxes * dimesnion);

    // load current data
    for (int i = 0; i < boxes; ++i) {
      // the current box
      for (int j = 0; j < dimesnion; ++j) {
        int tmp;
        if (scanf("%d", &tmp) != 1) {
          fprintf(stderr, "ERROR - input of a box isn't correct!\n");
          exit(EXIT_FAILURE);
        }
        *(data + j + (i * dimesnion)) = tmp;
      }
    }

    print_data(data, boxes, dimesnion);

    free(data);
    data = NULL;
  }

  return 0;
}

void print_data(int *data, int boxes, int dimesnion) {
  for (int i = 0; i < boxes; ++i) {
    for (int j = 0; j < dimesnion; ++j) {
      printf("%d ", *(data + j + (i * dimesnion)));
    }
    printf("\n");
  }
}