#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    t_queue* fila = create_queue();
    if (fila == NULL) {
        printf("Erro ao criar fila.\n");
        return 1;
    }

    // Inserindo elementos na fila
    printf("Inserindo elementos: 10, 20, 30...\n");
    in(fila, 10);
    in(fila, 20);
    in(fila, 30);

    // Exibindo tamanho
    printf("Tamanho da fila: %d\n", size(fila));

    // Topo da fila
    int topo;
    if (top(fila, &topo)) {
        printf("Primeiro elemento (topo da fila): %d\n", topo);
    } else {
        printf("Erro ao acessar o topo da fila.\n");
    }

    // Removendo elemento
    int removido;
    if (out(fila, &removido)) {
        printf("Elemento removido: %d\n", removido);
    } else {
        printf("Erro ao remover elemento.\n");
    }

    // Verificando tamanho após remoção
    printf("Tamanho após remoção: %d\n", size(fila));

    // Verifica se está vazia
    if (is_empty(fila)) {
        printf("A fila está vazia.\n");
    } else {
        printf("A fila não está vazia.\n");
    }

    // Limpando a fila
    printf("Esvaziando a fila...\n");
    clear(fila);
    printf("Tamanho após clear: %d\n", size(fila));

    if (is_empty(fila)) {
        printf("A fila agora está vazia.\n");
    } else {
        printf("A fila ainda contém elementos.\n");
    }

    // Fim
    printf("Encerrando o programa.\n");
    free(fila->itens);
    free(fila);
    return 0;
}
