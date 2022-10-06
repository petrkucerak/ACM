#include <stdio.h>
#include <stdlib.h>

#define DATA (data + j + (i * dimesnion))
#define NEXT_DATA (data + k + (i * dimesnion))
#define CURRENT_DATA (data + j + (i * dimesnion))

typedef struct box {
  int no;
  int *first_number;
  int sum;
} Box;

void print_data(int *data, int boxes, int dimesnion);
void print_boxes(Box *boxes_p, int boxes, int dimesnion);

int main(int argc, char const *argv[]) {
  printf("Stacking Boxes!\n");

  int status = 1;
  int *data = NULL;
  Box *boxes_p = NULL;

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
    boxes_p = malloc(sizeof(Box) * boxes);

    // load current data
    for (int i = 0; i < boxes; ++i) {
      // the current box
      for (int j = 0; j < dimesnion; ++j) {
        if (scanf("%d", DATA) != 1) {
          fprintf(stderr, "ERROR - input of a box isn't correct!\n");
          exit(EXIT_FAILURE);
        }
      }
      boxes_p[i].sum = 0;
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
      for (int j = 0; j < dimesnion; ++j) {
        boxes_p[i].sum += *CURRENT_DATA;
      }
      boxes_p[i].no = i + 1;
      boxes_p[i].first_number = (data + (i * dimesnion));
    }

    // sorting boxes
    // for j = 0
    for (int i = 0; i < boxes; ++i) {
      for (int k = i + 1; k < boxes; ++k) {
        if (*boxes_p[i].first_number > *boxes_p[k].first_number) {
          Box tmp;
          tmp.no = boxes_p[i].no;
          tmp.sum = boxes_p[i].sum;
          tmp.first_number = boxes_p[i].first_number;

          boxes_p[i].no = boxes_p[k].no;
          boxes_p[i].sum = boxes_p[k].sum;
          boxes_p[i].first_number = boxes_p[k].first_number;

          boxes_p[k].no = tmp.no;
          boxes_p[k].sum = tmp.sum;
          boxes_p[k].first_number = tmp.first_number;
        }
      }
    }

    for (int j = 1; j < dimesnion; ++j) {
      for (int i = 0; i < boxes; ++i) {
        for (int k = i + 1; k < boxes; ++k) {
          if (boxes_p[i].first_number[j] > boxes_p[k].first_number[j] &&
              boxes_p[i].first_number[j - 1] ==
                  boxes_p[k].first_number[j - 1]) {
            Box tmp;
            tmp.no = boxes_p[i].no;
            tmp.sum = boxes_p[i].sum;
            tmp.first_number = boxes_p[i].first_number;

            boxes_p[i].no = boxes_p[k].no;
            boxes_p[i].sum = boxes_p[k].sum;
            boxes_p[i].first_number = boxes_p[k].first_number;

            boxes_p[k].no = tmp.no;
            boxes_p[k].sum = tmp.sum;
            boxes_p[k].first_number = tmp.first_number;
          }
        }
      }
    }

    // print_data(data, boxes, dimesnion);
    print_boxes(boxes_p, boxes, dimesnion);

    // final calcule
    int final_sum = 1;
    
    printf(" - %d\n", final_sum);

    free(data);
    free(boxes_p);
    data = NULL;
    boxes_p = NULL;
  }

  return 0;
}

void print_data(int *data, int boxes, int dimesnion) {
  for (int i = 0; i < boxes; ++i) {
    for (int j = 0; j < dimesnion; ++j) {
      printf("%2d ", *(data + j + (i * dimesnion)));
    }
    printf("\n");
  }
}

void print_boxes(Box *boxes_p, int boxes, int dimesnion) {
  for (int i = 0; i < boxes; ++i) {
    for (int j = 0; j < dimesnion; ++j) {
      printf("%2d ", *(boxes_p[i].first_number + j));
    }
    printf("- sum: %d\n", boxes_p[i].sum);
  }
}