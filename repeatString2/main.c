#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long repeatedString(char* s, long n) {
  int vars[127] = {0};
  for (int j = 0; j < strlen(s); j++) {
    vars[s[j]]++;
  }
  long num_words = n / strlen(s);
  long rest_words = n % strlen(s);
  if (vars[97] == 0) {
    return 0;
  }
  long nb_chars = vars[97] * num_words;
  if (rest_words) {
    for (int j = 0; j < rest_words; j++) {
      if (s[j] == 'a') {
        nb_chars++;
      }
    }
  }
  return nb_chars;
}

int main(int argc, char const *argv[]) {
  long size = 1000000000000;
  char word[] = "a";
  long result = repeatedString(word, size);
  printf("%ld", result);
  return 0;
}
