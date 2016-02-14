PROGRAMS = auto lambda0 lambda1 null rvref shared smrtptrs unique weak

CC = clang++
CFLAGS=-Wall -O2 -std=c++11 -march=native
LIBS=

all: $(PROGRAMS)

.cc: ; $(CC) $(CFLAGS) $@.cc $(LIBS) -o $@
	strip $@

clean:
	rm $(PROGRAMS)
