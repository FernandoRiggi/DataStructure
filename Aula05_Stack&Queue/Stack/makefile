CC = gcc
CFLAGS = -Wall -Wextra -g

meu_programa: main.o stack.o
	$(CC) $(CFLAGS) -o meu_programa main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

clean:
	rm -f meu_programa main.o list.o
