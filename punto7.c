#include <stdio.h>
#include <stdlib.h>

int main() {
  int *data;
  data = malloc(100*sizeof(int));
  *data += 50;
  free(data);
  return 0;
}

