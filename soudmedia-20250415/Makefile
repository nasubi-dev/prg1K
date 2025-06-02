CC = cc
CFLAGS = -O2 -Wall
LDFLAGS = -lm

PROGRAM = wav_copy

OBJS = util.o

.SUFFIXES: .c .o

all: $(PROGRAM)

wav_copy: $(OBJS) wav_copy.c
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c -MMD -MP $<

.PHONY: clean
clean:
	rm -f *.o *.d $(PROGRAM);
	cd ./wav; rm -f *.wav
