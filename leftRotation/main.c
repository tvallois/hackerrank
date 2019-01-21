#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* rotLeft(int a_count, int* a, int d, int* result_count) {
  *result_count = a_count;
  int newTab[a_count];
  for (int i = 0; i < a_count; i++) {
    int index = i - d;
    if (index < 0) {
      index = a_count + index;
    }
    newTab[index] = a[i];
  }
  for (int i = 0; i < a_count; i++) {
    a[i] = newTab[i];
  }
  return a;
}

int main(int argc, char const *argv[]) {
  int a_count = 15;
  int d = 13;
  int a[] = {33, 47, 70, 37, 8, 53, 13, 93, 71, 72, 51, 100, 60, 87, 97};
  int result_count;
  int* result = rotLeft(a_count, a, d, &result_count);
  for (int i = 0; i < result_count; i++) {
      printf("%d", *(result + i));

      if (i != result_count - 1) {
          printf(" ");
      }
  }
  return 0;
}
