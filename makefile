CC = cc
CFLAGS = -Wall
LDFLAGS = -lncurses -lm

all: scroll

scroll: input.o main.o display.o
	$(CC) -o $@ $^ $(LDFLAGS)

input.o: input.c scroll.h
	$(CC) -c $(CFLAGS) $<

main.o: main.c scroll.h
	$(CC) -c $(CFLAGS) $<

display.o: display.c scroll.h
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -f *.o scroll
	reset
run: all
	./scroll
