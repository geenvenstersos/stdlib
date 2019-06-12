#ifndef _TEST_MEMCHR_H
#define _TEST_MEMCHR_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <setjmp.h>
#include <string.h>

#include "CuTest.h"

CuSuite* test_suit_memchr(void* sharedLib);
 

#endif