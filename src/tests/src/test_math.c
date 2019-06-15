#include <math.h>

#include "test_math.h"

#include "utilities.h"
#include "log.h"

void test_abs(CuTest *tc, void* param) {
   int (*fptr)(int) = (int (*) (int))param;

   if(fptr == NULL) {
      log_error("Could not get function pointer for 'abs'.");
   } else {
      log_info("Function pointer for 'abs' loaded successfully.");

      CuAssertIntEquals(tc, 1, fptr(-1));
      CuAssertIntEquals(tc, 100, fptr(-100));
      CuAssertIntEquals(tc, 10000000, fptr(-10000000));

      CuAssertIntEquals(tc, 1, fptr(1));
      CuAssertIntEquals(tc, 100, fptr(100));
      CuAssertIntEquals(tc, 10000000, fptr(10000000));
   }
}

void test_labs(CuTest *tc, void* param) {
   long (*fptr)(long) = (long (*) (long))param;

   if(fptr == NULL) {
      log_error("Could not get function pointer for 'labs'.");
   } else {
      log_info("Function pointer for 'labs' loaded successfully.");

      CuAssertIntEquals(tc, 1L, fptr(-1L));
      CuAssertIntEquals(tc, 100L, fptr(-100L));
      CuAssertIntEquals(tc, 10000000L, fptr(-10000000L));

      CuAssertIntEquals(tc, 1L, fptr(1L));
      CuAssertIntEquals(tc, 100L, fptr(100L));
      CuAssertIntEquals(tc, 10000000L, fptr(10000000L));
   }
}

void test_fabs(CuTest *tc, void* param) {
   float (*fptr)(float) = (float (*) (float))param;

   if(fptr == NULL) {
      log_error("Could not get function pointer for 'fabs'.");
   } else {
      log_info("Function pointer for 'fabs' loaded successfully.");

      CuAssertDblEquals(tc, 1.0, fptr(-1.0), 1e-5);
      CuAssertDblEquals(tc, 100.0, fptr(-100.0), 1e-5);
      CuAssertDblEquals(tc, 10000000.0, fptr(-10000000.0), 1e-5);

      CuAssertDblEquals(tc, 1.0, fptr(1.0), 1e-5);
      CuAssertDblEquals(tc, 100.0, fptr(100.0), 1e-5);
      CuAssertDblEquals(tc, 10000000.0, fptr(10000000.0), 1e-5);
   }
}

void test_sin(CuTest *tc, void* param) {
   float (*fptr)(float) = (float (*) (float))param;

   if(fptr == NULL) {
      log_error("Could not get function pointer for 'sin'.");
   } else {
      log_info("Function pointer for 'sin' loaded successfully.");

      CuAssertDblEquals(tc,  0, fptr(0),        1e-5);
      CuAssertDblEquals(tc,  1, fptr(M_PI/2.0), 1e-5);
      CuAssertDblEquals(tc,  0, fptr(M_PI),     1e-5);
      CuAssertDblEquals(tc, -1, fptr(3*M_PI/2), 1e-5);
   }
}

CuSuite* test_suit_math(void* sharedLib) {

   void* _sharedLib = sharedLib;

   CuSuite* suite = CuSuiteNew();

   //SUITE_ADD_TEST_PARAM(suite, test_abs, loadfunctionptr(sharedLib, "abs"));
   //SUITE_ADD_TEST_PARAM(suite, test_labs, loadfunctionptr(sharedLib, "labs"));
   //SUITE_ADD_TEST_PARAM(suite, test_fabs, loadfunctionptr(sharedLib, "fabs"));

   SUITE_ADD_TEST_PARAM(suite, test_sin, loadfunctionptr(sharedLib, "sin"));

   return suite;
}