IDIR =./include
LIBSRCDIR =./src
TESTSSRCDIR =./tests
BINDIR=./bin

ODIR=obj
TESTODIR=obj
LDIR =./lib

LIBS=


CC=gcc

LIBCFLAGS=-I$(IDIR) -nostdinc -ffreestanding -fpic
CFLAGS=-I$(IDIR)

_DEPS = string.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = strlen.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default: all


$(ODIR)/%.o: $(LIBSRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

static: $(BINDIR)/static/subsetlibc
dynamic: $(BINDIR)/dynamic/subsetlibc

all: static dynamic

$(BINDIR)/static/subsetlibc: $(OBJ)
	mkdir -p $(@D)
	ar rcs $(BINDIR)/static/subsetlibc.a $(OBJ)

$(BINDIR)/dynamic/subsetlibc: $(OBJ)
	mkdir -p $(@D)
	ar rcs $(BINDIR)/dynamic/subsetlibc.a $(OBJ)


.PHONY: all

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~ $(BINDIR)/*