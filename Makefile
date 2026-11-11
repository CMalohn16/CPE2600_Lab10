CFLAGS=-c -g -Wall -Werror
CC=gcc

all: alarm handler segfault

alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.o

handler: signal_handler.o
	$(CC) -o handler signal_handler.o

segfault: signal_segfault.o
	$(CC) -o segfault signal_segfault.o

clean:
	rm -f *.o alarm handler segfault

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

