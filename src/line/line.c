#include "line.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
  char *str;
  int len;
  int openBrackets[3];
  int closedBrackets[3];
};

int lineIsNull(LINE line) {
  if (line == NULL) {
    fprintf(stderr, "Error: trying to access a line that is NULL.\n");
    return 1;
  }
  return 0;
}

LINE lineNew(char *arg) {
  LINE new = (LINE) malloc(sizeof(struct line));

  new->len = strlen(arg);
  new->str = (char *) malloc(new->len+1);
  if (new->str == NULL) {
    fprintf(stderr, "Errror: unable to allocate dynamic memory.\n");
    exit(1);
  }
  memcpy(new->str, arg, new->len+1);

  new->openBrackets[0] = 0;
  new->openBrackets[1] = 0;
  new->openBrackets[2] = 0;
  
  new->closedBrackets[0] = 0;
  new->closedBrackets[1] = 0;
  new->closedBrackets[2] = 0;

  return new;
}

char *lineRead(LINE line) {
  if (lineIsNull(line))
    exit(1);
  
  return line->str;
}

int lineSetOpenBrackets(LINE line, int index) {
  if (lineIsNull(line))
    exit(1);
  line->openBrackets[index]++;
  return 1;
}

int *lineGetOpenBrackets(LINE line) {
  if (lineIsNull(line))
    exit(1);
  return line->openBrackets;
}

int lineSetClosedBrackets(LINE line, int index) {
  if (lineIsNull(line))
    exit(1);
  line->closedBrackets[index]++;
  return 1;
}

int *lineGetClosedBrackets(LINE line) {
  if (lineIsNull(line))
    exit(1);
  return line->closedBrackets;
}