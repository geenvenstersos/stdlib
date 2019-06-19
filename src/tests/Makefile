#Gets the include folder from the parent make

IDIR=./src
SRCDIR =./src
BINDIR=./bin
BUILDDIR=./build
ODIR=$(BUILDDIR)/obj

LIBS=-ldl
CC=gcc
_C_FLAGS=-I$(IDIR) -std=c89 -Wall -Wextra -pedantic -D__DEBUG__
CFLAGS=-I$(IDIR) -D__DEBUG__

SHE = '\#'

DEPS = $(shell find src | grep '\.h$$' | grep -v $(SHE) | sed -e 's:^\./::')
OBJ = $(shell find src | grep '\.c$$' | grep -v $(SHE) | sed -e 's:^src/:$(ODIR)/:' -e 's:\.c$$:\.o:')


default: all
all: clean test_cases

variables:
	echo $(LIBFILE)

test_cases: $(BINDIR)/test_cases
	@echo Running test cases...
	@cd $(BINDIR)
	@$(BINDIR)/test_cases $(LIBFILE)
	
$(ODIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $$(dirname $@)
	@$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/test_cases: $(OBJ)
	@mkdir -p $$(dirname $@)
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	

.PHONY: all

clean:
	@echo Cleaning tests files...
	@rm -rf *~ core $(INCDIR)/*~ $(BINDIR)/test_cases $(BUILDDIR)/* $(ODIR)/*.o
