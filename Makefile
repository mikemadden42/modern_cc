PROGRAMS = atomic auto for hello lambda0 lambda1 null read rvref shared size smrtptrs sysinfo token unique vector weak

CC = c++
CFLAGS=-Wall -O2 -std=c++11 -march=native
LIBS=

all: $(PROGRAMS)

.cc: ; $(CC) $(CFLAGS) $@.cc $(LIBS) -o $@
	strip $@

clean:
	rm $(PROGRAMS)
