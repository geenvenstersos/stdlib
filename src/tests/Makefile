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

_DEPS = utilities.h CuTest.h test_strlen.h test_memchr.h log.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = utilities.o CuTest.o test_strlen.o test_memchr.o tests.o log.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default: all
all: clean test_cases
test_cases: $(BINDIR)/test_cases
	cd $(BINDIR)
	$(BINDIR)/test_cases
	
	
$(ODIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/test_cases: $(OBJ)
	mkdir -p $(@D)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	

.PHONY: all

clean:
	rm -rf *~ core $(INCDIR)/*~ $(BINDIR)/test_cases $(BUILDDIR)/* $(ODIR)/*.o
