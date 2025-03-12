CC = gcc
CFLAGS = -Wall -Wextra

all: programa

programa: main.o ordered_list.o
	$(CC) $(CFLAGS) -o programa main.o ordered_list.o
main.o: main.c ordered_list.h
	$(CC) $(CFLAGS) -c -o main.o main.c
ordered_list.o: ordered_list.c ordered_list.h
	$(CC) $(CFLAGS) -c -o ordered_list.o ordered_list.c
clean:
	rm -f programa main.o ordered_list.o