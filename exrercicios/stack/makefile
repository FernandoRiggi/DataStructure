# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Arquivos-fonte
SRCS = main.c stack.c

# Arquivos objeto (substitui .c por .o)
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Como compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Como compilar os .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa arquivos gerados
clean:
	rm -f $(TARGET) $(OBJS)
