#include "line.h"

struct line {
  char *str;
  int len;
  int openBrackets[3];
  int closedBrackets[3];
};

