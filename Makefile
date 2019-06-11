IDIR =./include
LIBSRCDIR =./src
TESTSSRCDIR =./tests
BINDIR=./bin

ODIR=obj
TESTODIR=obj
LDIR =./lib

LIBS=


CC=gcc

LIBCFLAGS=-I$(IDIR) -nostdinc -ffreestanding -fPIC

_DEPS = string.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = strlen.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default: all


$(ODIR)/%.o: $(LIBSRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(LIBCFLAGS)

static: $(BINDIR)/static/subsetlibc
shared: $(BINDIR)/shared/subsetlibc

all: static shared

$(BINDIR)/static/subsetlibc: $(OBJ)
	mkdir -p $(@D)
	ar rcs $(BINDIR)/static/subsetlibc.a $(OBJ)

$(BINDIR)/shared/subsetlibc: $(OBJ)
	mkdir -p $(@D)
	gcc -shared $(OBJ) -o $(BINDIR)/shared/subsetlibc.so



.PHONY: all

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~ $(BINDIR)/*