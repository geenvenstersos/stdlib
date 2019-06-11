#include "test_strlen.h"

#include <string.h>

void test_strlen(CuTest *tc, const char* string, const int expected_size);



void test_strlen_null(CuTest *tc) {
   test_strlen(tc, NULL, 0);
}

void test_strlen_empty(CuTest *tc) {
   test_strlen(tc, "", 0);
}

void test_strlen_small(CuTest *tc) {
   test_strlen(tc, "SMALL+STRING", 12);
}

void test_strlen_medium(CuTest *tc) {
   test_strlen(tc, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", 150);
}

void test_strlen(CuTest *tc, const char* string, const int expected_size) {
   int actual = strlen(string);
   CuAssertIntEquals(tc, expected_size, actual);
}

CuSuite* test_suit_strlen() {
   CuSuite* suite = CuSuiteNew();

   SUITE_ADD_TEST(suite, test_strlen_empty);
   SUITE_ADD_TEST(suite, test_strlen_small);
   SUITE_ADD_TEST(suite, test_strlen_medium);

   return suite;
}