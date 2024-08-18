#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>

#include "line.h"
#include "list.h"

void testLine_create() {
  LINE line = lineNew("");
  CU_ASSERT_PTR_NOT_NULL(line);
}

void testLine_content() {
  LINE line = lineNew("Test");
  char *content = lineRead(line);
  CU_ASSERT_EQUAL(content[0], 'T');
  CU_ASSERT_EQUAL(content[1], 'e');
  CU_ASSERT_EQUAL(content[2], 's');
  CU_ASSERT_EQUAL(content[3], 't');
  CU_ASSERT_EQUAL(content[4], '\0');
}

void testLine_brackets() {
  LINE line = lineNew("");
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
  
  CU_ASSERT_EQUAL(opened[0], 1);
  CU_ASSERT_EQUAL(opened[1], 3);
  CU_ASSERT_EQUAL(opened[2], 2);
  CU_ASSERT_EQUAL(closed[0], 3);
  CU_ASSERT_EQUAL(closed[1], 1);
  CU_ASSERT_EQUAL(closed[2], 1);
}

int main() {
  if (CU_initialize_registry() != CUE_SUCCESS)
    return CU_get_error();

  CU_pSuite pSuite = CU_add_suite("Line Test Suite", 0, 0);
  if (pSuite == NULL) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (CU_add_test(pSuite, "Testing creation", testLine_create) == NULL ||
    CU_add_test(pSuite, "Testing string content", testLine_content) == NULL ||
    CU_add_test(pSuite, "Testing brackets", testLine_brackets) == NULL
  ) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}