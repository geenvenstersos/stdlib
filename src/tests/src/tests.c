#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"

#include "test_strlen.h"

void RunAllTests(void) {
   CuString *output = CuStringNew();
   CuSuite* suite = CuSuiteNew();
   
   CuSuiteAddSuite(suite, test_suit_strlen());

   CuSuiteRun(suite);
   CuSuiteSummary(suite, output);
   CuSuiteDetails(suite, output);
   printf("%s\n", output->buffer);
}

int main(void) {
   RunAllTests();
}