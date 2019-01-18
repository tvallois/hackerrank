#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CounterValue
{
  char* key;
  int value;
} CounterValue;

typedef struct Counter
{
  int len;
  int cap;
  CounterValue *values;
} Counter;

Counter initCounter() {
  struct Counter first;
  first.len = 0;
  first.cap = 10;
  first.values = malloc(10 * sizeof(CounterValue));
  return first;
}

bool checkExistingKey(Counter* counter, char* key) {
    for (int i = 0; i < counter->len; i++) {
        if (strcmp(counter->values[i].key, key) == 0) {
            counter->values[i].value++;
            return true;
        }
    }
    return false;
}

void incrementCounter(Counter* counter, char* key) {
    bool existing_key = checkExistingKey(counter, key);
    if (!existing_key){
        if (counter->len == counter->cap) {
            counter->cap *= 2;
            counter->values = realloc(counter->values, counter->cap * sizeof(CounterValue));
        }
        counter->values[counter->len].key = strdup(key);
        counter->values[counter->len].value = 1;
        counter->len++;
    }
}

long getMaxOnCounter(Counter* counter) {
    long max = 0;
    for (int i = 0; i < counter->len; i++) {
        if (counter->values[i].value > max) {
            max = counter->values[i].value;
        }
    }
    return max;
}

void freeCounter(Counter* counter) {
  for (int i = 0; i < counter->len; i++) {
    free(counter->values[i].key);
  }
  free(counter->values);
}


long repeatedString(char* s, long n) {
  char newWord[n + 1];
  for (int i = 0 ; i < n ; i++) {
    long j = i % strlen(s);
    newWord[i] = s[j];
    newWord[i+1] = '\0';
  }
  Counter counter = initCounter();
  for (int j = 0; j < strlen(newWord); j++) {
      char test[2];
      memcpy(test, &newWord[j], 1* sizeof(char));
      incrementCounter(&counter, test);
  }
  long result = getMaxOnCounter(&counter);
  freeCounter(&counter);
  return result;
}

int main(int argc, char const *argv[]) {
  long size = 100;
  char word[] = "aba";
  long result = repeatedString(word, size);
  printf("%ld", result);
  return 0;
}
