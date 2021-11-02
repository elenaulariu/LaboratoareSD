#include "helpers.h"

int double_equals(double a, double b)
{
    return fabs(a - b) < 0.0001;
}

int compare_arrays(int v1[], int v2[], size_t len) {
  for (size_t i = 0; i < len; i++) {
    if (v1[i] != v2[i]) {
      return 0;
    }
  }
  return 1;
}

void print_vector(int buffer[], size_t vector_length) {
    printf("[");
    for (size_t index = 0; index < vector_length; index++) {
        printf("%d", buffer[index]);
        if (index < vector_length - 1)
            printf(", ");
    }
    printf("]\n");
}
