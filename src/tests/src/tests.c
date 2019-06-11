#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"

#include "utilities.h"

#include "test_strlen.h"

void RunAllTests(void* sharedLib);

int main(void) {
   
   const char* sharedLibName = "/home/rsouza/Projecten/OPERATING_SYSTEMS/SIDE_PROJECTS/subsetlibc/src/tests/bin/subsetlibc.so";
   
   void* sharedLib = loadLibrary(sharedLibName);

   if(sharedLib == NULL) {
      printf("Library subsetlibc.so could not be loaded.\n");
      return EXIT_FAILURE;
   } else {
      
      printf("Library subsetlibc.so loaded suceesfully.\n");

      RunAllTests(sharedLib);

      return EXIT_SUCCESS;
   }
}

void RunAllTests(void* sharedLib) {

   CuString *output = CuStringNew();
   CuSuite* suite = CuSuiteNew();
   
   CuSuiteAddSuite(suite, test_suit_strlen(sharedLib));

   CuSuiteRun(suite);
   CuSuiteSummary(suite, output);
   CuSuiteDetails(suite, output);

   printf("%s\n", output->buffer);
}