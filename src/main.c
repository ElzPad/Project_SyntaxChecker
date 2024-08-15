#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1023

int main(int argc, char *argv[]) {
  FILE *fpIn, *fpOut;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <sourceFile> <outputFile>\n", argv[0]);
    return -1;
  }

  fpIn = fopen(argv[1], "r");
  if (fpIn == NULL) {
    fprintf(stdout, "An error occurred while opening the input file.\n");
    return -1;
  }
  fpOut = fopen(argv[2], "w");
  if (fpOut == NULL) {
    fprintf(stdout, "An error occurred while opening the output file.\n");
    return -1;
  }

  fclose(fpIn);
  fclose(fpOut);
  return 0;
}