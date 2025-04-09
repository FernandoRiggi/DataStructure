#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Função auxiliar para imprimir a lista
void print_list(const char* label, t_list* list) {
    printf("%s\n", label);
    if (list == NULL || is_empty(list)) {
        printf("[Lista vazia]\n");
        return;
    }
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(i, list));
    }
    printf("\n");
}

int main() {
    t_list* list = create_list();
    if (list == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    // Adicionando elementos à lista
    append(10, list);
    append(20, list);
    append(30, list);
    append(20, list);
    append(40, list);
    append(20, list);

    print_list("Lista após inserções:", list);

    // Removendo todas as ocorrências do número 20
    printf("\nRemovendo todas as ocorrências do número 20...\n");
    int removidos = remove_all_occurences(20, list);
    printf("Total de ocorrências removidas: %d\n", removidos);
    print_list("Lista após remoções:", list);

    // Copiando a lista
    t_list* copy = copy_list(list);
    if (copy == NULL) {
        printf("Erro ao copiar a lista.\n");
        free(list->itens);
        free(list);
        return 1;
    }
    print_list("\nCópia da lista:", copy);

    // Invertendo a lista original
    invert_list(list);
    print_list("\nLista invertida:", list);

    // Liberando memória
    free(list->itens);
    free(list);
    free(copy->itens);
    free(copy);

    return 0;
}
