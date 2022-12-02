SRCS	= $(wildcard ./*.c)
OBJS	= $(patsubst ./%.c, ./%.o, $(SRCS))
CFLAGS	= -Wall -std=c11 -g -c
CC		= gcc

default: build
	./main

build: $(OBJS)
	$(CC) $^ -lm -o main

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@
