#include <string.h>

#include "test_strlen.h"
#include "utilities.h"


#define STRLEN "strlen"
#define STRLEN_API size_t (*) (const char*)

void test_strlen(CuTest *tc, const char* string, const int expected_size);
void test_strlen_arbitrary(CuTest *tc, const char chr, int size);

size_t (*fptr_strlen)(const char*);


void test_strlen_null(CuTest *tc) {
   test_strlen(tc, NULL, 0);
}

void test_strlen_empty(CuTest *tc) {
   test_strlen(tc, "", 0);
}

void test_strlen_small(CuTest *tc) {
   test_strlen_arbitrary(tc, 'X', 10);
}

void test_strlen_medium(CuTest *tc) {
   test_strlen_arbitrary(tc, 'X', 100);
}

void test_strlen_big(CuTest *tc) {
   test_strlen_arbitrary(tc, 'X', 1000);
}

void test_strlen_huge(CuTest *tc) {
   test_strlen_arbitrary(tc, 'X', 1000000);
}

void test_strlen_arbitrary(CuTest *tc, const char chr, int size) {

   char* string_ptr = (char*)malloc(size*sizeof(char));

   if(string_ptr != NULL) {
      for(int i = 0; i < size; i++) {
         string_ptr[i] = chr;
      }
      
      test_strlen(tc, string_ptr, size);

      free(string_ptr);
   }
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
      SUITE_ADD_TEST(suite, test_strlen_big);
      SUITE_ADD_TEST(suite, test_strlen_huge);

   }

   return suite;
}