CFLAGS=-c -g -Wall
CC=gcc

all: alarm handler segfault sigaction send receive recvtennis serve

alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.c

handler: signal_handler.o
	$(CC) -o handler signal_handler.c

segfault: signal_segfault.o
	$(CC) -o segfault signal_segfault.c

sigaction: signal_sigaction.o
	$(CC) -o sigaction signal_sigaction.c

send: send_signal.o
	$(CC) -o send send_signal.c

receive: recv_signal.o
	$(CC) -o receive recv_signal.c

serve: serve.o
	$(CC) -o serve serve.c tennis_scoring.c

recvtennis: receive_tennis.o
	$(CC) -o recvtennis receive_tennis.c tennis_scoring.c

clean:
	rm -f *.o alarm handler segfault sigaction send receive recvtennis serve

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

