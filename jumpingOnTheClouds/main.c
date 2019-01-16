#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jumpingOnClouds(int c_count, int* c) {
  int result = -1;
  for (int i = 0; i < c_count; i++) {
    if (c[i + 2] == 0 && i < c_count - 2) {
      i += 1;
    }
    result += 1;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int nbOfClouds = 6;
  int clouds[nbOfClouds];
  clouds[0] = 0;
  clouds[1] = 1;
  clouds[2] = 0;
  clouds[3] = 0;
  clouds[4] = 0;
  clouds[5] = 1;
  clouds[6] = 0;
  int result = jumpingOnClouds(nbOfClouds, clouds);
  printf("%d\n", result);
  return 0;
}
