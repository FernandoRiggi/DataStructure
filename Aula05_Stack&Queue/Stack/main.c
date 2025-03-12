#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    t_stack* stack = create_stack(5);
    
    printf("Inserindo valores na pilha...\n");
    for (int i = 1; i <= 7; i++) {
        if (push(stack, i)) {
            printf("Empilhado: %d\n", i);
        } else {
            printf("Falha ao empilhar %d\n", i);
        }
    }

    int topValue;
    if (top(stack, &topValue) == 1) {
        printf("Topo da pilha: %d\n", topValue);
    } else {
        printf("A pilha está vazia!\n");
    }

    printf("Removendo elementos...\n");
    int removedValue;
    while (!is_empty(stack)) {
        if (pop(stack, &removedValue)) {
            printf("Elemento removido: %d. Novo tamanho: %d\n", removedValue, size(stack));
        }
    }

    printf("Limpando a pilha...\n");
    clear(stack);
    printf("Tamanho da pilha após limpar: %d\n", size(stack));

    destroy(stack);
    printf("Pilha destruída!\n");
    
    return 0;
}