#include <string.h>

#include "test_memchr.h"
#include "utilities.h"
#include "log.h"


#define MEMCHR "memchr"
#define MEMCHR_API void *(*)(const void *str, int c, size_t n)



void* (*fptr_memchr)(const void *str, int c, size_t n);
void test_memchr(CuTest *tc, char* string, int len, int chartofind, int expected);
void test_memchr_from_data(CuTest *tc, int size, int position, char tofind);

void test_memchr_empty(CuTest *tc) {
   test_memchr(tc, "", 1, '+', 0);
}

void test_memchr_small(CuTest *tc, void* param) {
   test_memchr_from_data(tc, 10, 5, '+');
}

void test_memchr_medium(CuTest *tc, void* param) {
   test_memchr_from_data(tc, 100000, 50000, '+');
}

void test_memchr_big(CuTest *tc, void* param) {
   test_memchr_from_data(tc, 1000000, 500000, '+');
}

void test_memchr_huge(CuTest *tc, void* param) {
   test_memchr_from_data(tc, 10000000, 500000, '+');
}

void test_memchr_from_data(CuTest *tc, int size, int position, char tofind) {

   char* string = (char*)malloc(size);
   string[position] = tofind;
   
   test_memchr(tc, string, size, tofind, position);

   free(string);
}

void test_memchr(CuTest *tc, char* string, int len, int chartofind, int expected) {

   char* actual = (char*)fptr_memchr(string, chartofind, len);
   CuAssertIntEquals(tc, expected, actual - string);
}

CuSuite* test_suit_memchr(void* sharedLib) {

   CuSuite* suite = CuSuiteNew();

   fptr_memchr = (MEMCHR_API)loadfunctionptr(sharedLib, MEMCHR);

   if(fptr_memchr == NULL) {
      log_info("Could not get function pointer for '%s'.", MEMCHR);
   } else {

      log_info("Function pointer for '%s' loaded succesfully.", MEMCHR);

      SUITE_ADD_TEST(suite, test_memchr_small);
      SUITE_ADD_TEST(suite, test_memchr_medium);
      SUITE_ADD_TEST(suite, test_memchr_big);
      SUITE_ADD_TEST(suite, test_memchr_huge);
  }

   return suite;
}