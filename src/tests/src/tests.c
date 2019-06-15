#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"

#include "utilities.h"
#include "log.h"

#include "test_strlen.h"
#include "test_memchr.h"
#include "test_math.h"

void RunAllTests(void* sharedLib);

int main(int argc, char** argv) {

   if(argc != 2 && argv[1] == NULL) {
      log_error("The location of the Library 'subsetlibc.so' should be provided as argument.");
      return EXIT_FAILURE;
   }

   const char* sharedLibName = argv[1];

   void* sharedLib = loadlibrary(sharedLibName);

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
   CuSuiteAddSuite(suite, test_suit_math(sharedLib));
   

   CuSuiteRun(suite);
   CuSuiteSummary(suite, output);
   CuSuiteDetails(suite, output);

   log_info("TEST OUTPUT\n\n%s\n", output->buffer);

}