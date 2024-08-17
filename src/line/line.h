#ifndef TLINE_INCLUDED

  #define TLINE_INCLUDED 1

  typedef struct line *LINE;

  LINE lineNew(char *str);
  char *lineRead(LINE line);
  int lineSetOpenBrackets(LINE line, int index);
  int *lineGetOpenBrackets(LINE line);
  int lineSetClosedBrackets(LINE line, int index);
  int *lineGetClosedBrackets(LINE line);
#endif