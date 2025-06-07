CC = gcc
CFLAGS = -O2 -Wall
LDFLAGS = -lm

PROGRAM = compressor tremolo vibrato

OBJS = util.o

.SUFFIXES: .c .o

all: $(PROGRAM)

compressor: $(OBJS) compressor.c
	$(CC) $(CFLAGS) -o $@ $^

tremolo: $(OBJS) tremolo.c
	$(CC) $(CFLAGS) -o $@ $^

vibrato: $(OBJS) vibrato.c
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c -MMD -MP $<

.PHONY: clean
clean:
	rm -f *.o *.d $(PROGRAM)
