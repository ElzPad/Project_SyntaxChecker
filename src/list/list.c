#include "list.h"
#include "line.h"

typedef struct node *link;

struct node {
  LINE line;
  link next;
};

struct list {
  link head;
  int dim;
};