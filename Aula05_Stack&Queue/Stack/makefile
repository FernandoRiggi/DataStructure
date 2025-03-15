CC = gcc
CFLAGS = -Wall -Wextra -g

# Regra para compilar o programa
meu_programa: main.o stack.o quicksort.o
	$(CC) $(CFLAGS) -o meu_programa main.o stack.o quicksort.o

# Compilando o arquivo main.c
main.o: main.c stack.h quicksort.h
	$(CC) $(CFLAGS) -c -o main.o main.c

# Compilando o arquivo stack.c
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

# Compilando o arquivo quicksort.c
quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c -o quicksort.o quicksort.c

# Limpar os arquivos gerados
clean:
	rm -f meu_programa main.o stack.o quicksort.o
