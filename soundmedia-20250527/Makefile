CC = gcc
CFLAGS = -O2 -Wall
LIBS = -lm

PROGRAM = delay reverb hard_distortion soft_distortion

OBJS = util.o

.SUFFIXES: .c .o

all: $(PROGRAM)

delay: $(OBJS) delay.c
	$(CC) $(CFLAGS) -o $@ $^ ${LIBS}

reverb: $(OBJS) reverb.c
	$(CC) $(CFLAGS) -o $@ $^ ${LIBS}

hard_distortion: $(OBJS) hard_distortion.c
	$(CC) $(CFLAGS) -o $@ $^ ${LIBS}

soft_distortion: $(OBJS) soft_distortion.c
	$(CC) $(CFLAGS) -o $@ $^ ${LIBS}

%.o: %.c
	$(CC) -c -MMD -MP $<

.PHONY: clean
clean:
	rm -f *.o *.d $(PROGRAM) delay.wav reverb.wav hard_distortion.wav soft_distortion.wav
