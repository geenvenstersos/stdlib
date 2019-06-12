#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"

#include "utilities.h"
#include "log.h"

#include "test_strlen.h"
#include "test_memchr.h"

void RunAllTests(void* sharedLib);

int main(void) {
   
   char message[100];
   const char* sharedLibName = "/home/rsouza/Projecten/OPERATING_SYSTEMS/SIDE_PROJECTS/subsetlibc/src/tests/bin/subsetlibc.so";
   
   void* sharedLib = loadLibrary(sharedLibName);


   if(sharedLib == NULL) {
      log_error("Library 'subsetlibc.so' could not be loaded.");
      return EXIT_FAILURE;
   } else {
      
      log_info("Library 'subsetlibc.so' loaded successfully.");

      RunAllTests(sharedLib);

      return EXIT_SUCCESS;
   }
}

void RunAllTests(void* sharedLib) {

   CuString *output = CuStringNew();
   CuSuite* suite = CuSuiteNew();
   
   CuSuiteAddSuite(suite, test_suit_strlen(sharedLib));
   CuSuiteAddSuite(suite, test_suit_memchr(sharedLib));
   

   CuSuiteRun(suite);
   CuSuiteSummary(suite, output);
   CuSuiteDetails(suite, output);

   log_info("TEST OUTPUT\n\n%s\n", output->buffer);

}