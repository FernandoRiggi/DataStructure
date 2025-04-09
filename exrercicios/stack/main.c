#include <stdio.h>
#include "stack.h"

int main() {
    t_stack* stack = create_stack();
    if (stack == NULL) {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }

    printf("Empilhando elementos: 10, 20, 30...\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Tamanho da pilha: %d\n", size(stack));

    int topo;
    if (top(stack, &topo))
        printf("Topo da pilha: %d\n", topo);

    int desempilhado;
    if (pop(stack, &desempilhado))
        printf("Elemento desempilhado: %d\n", desempilhado);

    printf("Tamanho após pop: %d\n", size(stack));

    if (is_empty(stack))
        printf("A pilha está vazia.\n");
    else
        printf("A pilha não está vazia.\n");

    printf("Esvaziando pilha...\n");
    clear(stack);

    printf("Tamanho após clear: %d\n", size(stack));

    if (is_empty(stack))
        printf("A pilha agora está vazia.\n");

    printf("Destruindo a pilha...\n");
    destroy(stack);

    return 0;
}
