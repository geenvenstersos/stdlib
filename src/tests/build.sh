#!/bin/bash

clear

BINDIR=./bin


make LIBFILE=`pwd`/../../bin/shared/subsetlibc.so

if [ $? -eq 0 ]; then
    ${BINDIR}/test_cases
    echo $?
else
    echo FAIL
fi


