# Nome do executável
TARGET = list_test

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Arquivos-fonte
SRCS = main.c LinkedList.c

# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Regra principal
all: $(TARGET)

# Como compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Como compilar os arquivos .o a partir dos .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)
