#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void panic(char *error) {
  fprintf(stderr, "%s\n", error);
}
