#Gets the include folder from the parent make
#IDIR?=./include
#LDIR?=./lib


#IDIR+=./include
IDIR=./src
SRCDIR =./src
BINDIR=./bin
BUILDDIR=./build
ODIR=$(BUILDDIR)/obj

LIBS=-ldl
CC=gcc
_C_FLAGS=-I$(IDIR) -std=c89 -Wall -Wextra -pedantic
CFLAGS=-I$(IDIR)

_DEPS = utilities.h CuTest.h test_strlen.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = utilities.o CuTest.o test_strlen.o tests.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default: all
all: test_cases
test_cases: $(BINDIR)/test_cases

variables:
	echo $(DEPS)
	echo $(OBJ)
	echo $(ODIR)

$(ODIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/test_cases: $(OBJ)
	mkdir -p $(@D)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: all

clean:
	rm -rf *~ core $(INCDIR)/*~ $(BINDIR)/* $(BUILDDIR)/* $(ODIR)/*.o