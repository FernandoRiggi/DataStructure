# Nome do executável
TARGET = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Arquivos fonte
SRCS = main.c list.c

# Gera os arquivos .o (objetos) a partir dos .c
OBJS = $(SRCS:.c=.o)

# Regra principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Limpa os arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(TARGET)
