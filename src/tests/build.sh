#!/bin/bash

clear

LIBINCDIR=../../include
LIBDIR=../../include
BINDIR=./bin

#make clean
#make all IDIR=${LIBINCDIR} LDIR=${LIBDIR}
make all

if [ $? -eq 0 ]; then

    #clear 

    ${BINDIR}/test_cases

    echo $?
else
    echo FAIL
fi


