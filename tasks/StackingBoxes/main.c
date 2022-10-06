#include <stdio.h>
#include <stdlib.h>

#define DATA (data + j + (i * dimesnion))
#define NEXT_DATA (data + k + (i * dimesnion))
#define CURRENT_DATA (data + j + (i * dimesnion))

void print_data(int *data, int boxes, int dimesnion);

typedef struct box {
  int no;
  int *first_number;
} Box;

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
        if (scanf("%d", DATA) != 1) {
          fprintf(stderr, "ERROR - input of a box isn't correct!\n");
          exit(EXIT_FAILURE);
        }
      }
      // sorting dimensions
      for (int j = 0; j < dimesnion; ++j) {
        for (int k = j + 1; k < dimesnion; ++k) {
          if (*CURRENT_DATA > *NEXT_DATA) {
            int tmp = *CURRENT_DATA;
            *CURRENT_DATA = *NEXT_DATA;
            *NEXT_DATA = tmp;
          }
        }
      }

      
    }

    // sorting boxes
    for (int i = 0; i < boxes; ++i) {
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