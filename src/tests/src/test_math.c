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

void test_auxiliary_trig_power(CuTest *tc, void* param) {

   unsigned long long int (*fptr)(int, int, unsigned long long int, int) = 
      (unsigned long long int (*)(int, int, unsigned long long int, int))param;

#ifndef NDEBUG 
   /* TEST FOR ERROR - FLAG NDEBUG */
   CuAssertIntEquals(tc, 0, fptr(2, 2, 1, 1));
#endif

   /* BASE = 2 */
   unsigned long long int base2 = 2;

   unsigned long long int base_2_2 = fptr(base2, 2, base2, 1);
   CuAssertIntEquals(tc,  4, base_2_2);

   unsigned long long int base_2_4 = fptr(base2, 4, base_2_2, 2);
   CuAssertIntEquals(tc,  16, base_2_4);

   unsigned long long int base_2_10 = fptr(base2, 10, base_2_4, 4);
   CuAssertIntEquals(tc,  1024, base_2_10);

   /* BASE = 3 */
   unsigned long long int base3 = 3;
   unsigned long long int base_3_2 = fptr(base3, 2, base3, 1);
   CuAssertIntEquals(tc,  9, base_3_2);

   unsigned long long int base_3_4 = fptr(base3, 4, base_3_2, 2);
   CuAssertIntEquals(tc,  81, base_3_4);

   unsigned long long int base_3_10 = fptr(base3, 10, base_3_4, 4);
   CuAssertIntEquals(tc,  59049, base_3_10);

   /* BASE = 17 */
   unsigned long long int base17 = 17;
   unsigned long long int base_17_2 = fptr(base17, 2, base17, 1);
   CuAssertIntEquals(tc,  289, base_17_2);

   unsigned long long int base_17_4 = fptr(base17, 4, base_17_2, 2);
   CuAssertIntEquals(tc,  83521, base_17_4);

   unsigned long long int base_17_6 = fptr(base17, 6, base_17_4, 4);
   CuAssertIntEquals(tc,  24137569, base_17_6);


}

void test_auxiliary_trig_factorial(CuTest *tc, void* param) {

   unsigned long long int (*fptr)(int, unsigned long long int, int) = 
      (unsigned long long int (*)(int, unsigned long long int, int ))param;

   unsigned long long int fact = fptr(4, 1, 1);
   CuAssertIntEquals(tc,  24, fact);

   fact = fptr(5, fact, 4);
   CuAssertIntEquals(tc,  120, fact);


   fact = fptr(11, fact, 5);
   CuAssertIntEquals(tc,  39916800, fact);

}

void test_sin(CuTest *tc, void* param) {
   double (*fptr)(double) = (double (*) (double))param;

   if(fptr == NULL) {
      log_error("Could not get function pointer for 'sin'.");
   } else {
      log_info("Function pointer for 'sin' loaded successfully.");

      CuAssertDblEquals(tc,  0,        fptr(0),       1e-5);
      CuAssertDblEquals(tc,  1,        fptr(M_PI/2.0),1e-5);
      CuAssertDblEquals(tc,  0,        fptr(M_PI),    1e-5);
      CuAssertDblEquals(tc, -1,        fptr(3*M_PI/2),1e-5);
   }
}

void test_cos(CuTest *tc, void* param) {
   double (*fptr)(double) = (double (*) (double))param;

   if(fptr == NULL) {
      log_error("Could not get function pointer for 'cos'.");
   } else {
      log_info("Function pointer for 'cos' loaded successfully.");

      CuAssertDblEquals(tc,  1,        fptr(0),       1e-5);
      CuAssertDblEquals(tc,  0,        fptr(M_PI/2.0),1e-5);
      CuAssertDblEquals(tc,  -1,        fptr(M_PI),    1e-5);
      CuAssertDblEquals(tc, 0,        fptr(3*M_PI/2),1e-5);
   }
}

CuSuite* test_suit_math(void* sharedLib) {

   void* _sharedLib = sharedLib;

   CuSuite* suite = CuSuiteNew();

   SUITE_ADD_TEST_PARAM(suite, test_abs, loadfunctionptr(sharedLib, "abs"));
   SUITE_ADD_TEST_PARAM(suite, test_labs, loadfunctionptr(sharedLib, "labs"));
   SUITE_ADD_TEST_PARAM(suite, test_fabs, loadfunctionptr(sharedLib, "fabs"));

   SUITE_ADD_TEST_PARAM(suite, test_auxiliary_trig_power, loadfunctionptr(sharedLib, "_power"));
   SUITE_ADD_TEST_PARAM(suite, test_auxiliary_trig_factorial, loadfunctionptr(sharedLib, "_factorial"));

   SUITE_ADD_TEST_PARAM(suite, test_sin, loadfunctionptr(sharedLib, "sin"));
   SUITE_ADD_TEST_PARAM(suite, test_cos, loadfunctionptr(sharedLib, "cos"));
   
   return suite;
}