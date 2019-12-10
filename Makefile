CC=gcc
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:src/%.c=obj/%.o)
CFLAGS=-Isrc -Wall -g
LFLAGS=-lncurses -lm

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

dev: $(OBJS)
	$(CC) -o test.out $^ $(LFLAGS)

clean:
	rm -f obj/*.o