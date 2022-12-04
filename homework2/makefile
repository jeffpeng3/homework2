SRCS	= $(wildcard ./*.c)
OBJS	= $(patsubst ./%.c, ./%.o, $(SRCS))
CFLAGS	= -Wall -std=c11 -g -c
BINFLAGS= -Wall -std=c11 -g
CC		= gcc

default: $(OBJS)
	$(CC) $(BINFLAGS) $^ -o main
	

run: default
	./main

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm *.o