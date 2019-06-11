#include <string.h>

#include "test_strlen.h"
#include "utilities.h"

void test_strlen(CuTest *tc, const char* string, const int expected_size);

#define STRLEN "strlen"
#define STRLEN_API size_t (*) (const char*)

size_t (*fptr_strlen)(const char*);


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
   int actual = fptr_strlen(string);
   CuAssertIntEquals(tc, expected_size, actual);
}

CuSuite* test_suit_strlen(void* sharedLib) {

   CuSuite* suite = CuSuiteNew();

   fptr_strlen = (STRLEN_API)getFunctionPointer(sharedLib, STRLEN);

   if(fptr_strlen == NULL) {
      printf("Could not get function pointer for %s.\n\n\n", STRLEN);
   } else {

      printf("Function pointer for %s loaded succesfully.\n\n\n", STRLEN);

      SUITE_ADD_TEST(suite, test_strlen_empty);
      SUITE_ADD_TEST(suite, test_strlen_small);
      SUITE_ADD_TEST(suite, test_strlen_medium);

   }

   return suite;
}