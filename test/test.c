#include <stdio.h>

#include "line.h"
#include "list.h"

int main() {
  LINE line = lineNew("Hello, world!");
  int *opened, *closed;

  lineSetOpenBrackets(line, 0);
  lineSetOpenBrackets(line, 1);
  lineSetOpenBrackets(line, 2);
  lineSetOpenBrackets(line, 1);
  lineSetOpenBrackets(line, 1);
  lineSetOpenBrackets(line, 2);

  lineSetClosedBrackets(line, 0);
  lineSetClosedBrackets(line, 0);
  lineSetClosedBrackets(line, 1);
  lineSetClosedBrackets(line, 2);
  lineSetClosedBrackets(line, 0);

  opened = lineGetOpenBrackets(line);
  closed = lineGetClosedBrackets(line);

  printf("%s (%d, %d, %d) (%d, %d, %d)\n", lineRead(line), opened[0], opened[1], opened[2], closed[0], closed[1], closed[2]);
  return 0;
}