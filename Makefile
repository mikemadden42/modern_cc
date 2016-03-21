PROGRAMS = auto for hello lambda0 lambda1 null rvref shared size smrtptrs unique vector weak

CC = g++
CFLAGS=-Wall -O2 -std=c++11 -march=native
LIBS=

all: $(PROGRAMS)

.cc: ; $(CC) $(CFLAGS) $@.cc $(LIBS) -o $@
	strip $@

clean:
	rm $(PROGRAMS)
