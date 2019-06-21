IDIR =./include
LIBSRCDIR =./src
TESTSSRCDIR =./tests
BINDIR=./bin

ODIR=obj
TESTODIR=obj
LDIR =./lib

LIBS=


CC=gcc

LIBCFLAGS=-I$(IDIR) -nostdinc -nostdlib -ffreestanding -fPIC

SHE = '\#'

HEADERS = $(shell find . -name tests -prune -o -print | grep '\.h$$' | grep -v $(SHE) | sed -e 's:^\./::')

OBJECTS = $(shell find src -name tests -prune -o -print | grep '\.c$$' | grep -v $(SHE) | sed -e 's:^src/:obj/:' -e 's:\.c$$:\.o:')


default: all


$(ODIR)/%.o: $(LIBSRCDIR)/%.c $(HEADERS)
	@mkdir -p $$(dirname $@)
	$(CC) -c -o $@ $< $(LIBCFLAGS)

static: $(BINDIR)/static/subsetlibc
shared: $(BINDIR)/shared/subsetlibc

all: static shared tests

variables:
	echo $(OBJECTS)
	echo $(HEADERS)


$(BINDIR)/static/subsetlibc: $(OBJECTS)
	@echo Building static library...
	mkdir -p $(@D)
	ar rcs $(BINDIR)/static/subsetlibc.a $(OBJECTS)

$(BINDIR)/shared/subsetlibc: $(OBJECTS)
	@echo Building shared library...
	mkdir -p $(@D)
	gcc -shared $(OBJECTS) -o $(BINDIR)/shared/subsetlibc.so

tests: static shared
	@echo Calling external tests makefile...
	$(MAKE) -C ./src/$@ all LIBFILE=`pwd`/$(BINDIR)/shared/subsetlibc.so


.PHONY: all

clean:
	@echo Cleaning build files...
	@rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~ $(BINDIR)/*
	@$(MAKE) -C ./src/tests/ clean
