#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"

int main() {
    // Criando listas para teste
    t_ordered_list* list1 = create_list(5);
    t_ordered_list* list2 = create_list(5);

    // Testando inserção de elementos
    printf("Inserindo elementos na lista 1...\n");
    insert(list1, 3);
    insert(list1, 1);
    insert(list1, 4);
    insert(list1, 2);
    insert(list1, 5);

    printf("Lista 1 após inserções:\n");
    print_ordered_list(list1);

    // Testando busca
    printf("\nBuscando o valor 3 na lista 1...\n");
    int index = search(list1, 3);
    printf("Índice de 3: %d\n", index);

    printf("\nBuscando o valor 6 na lista 1...\n");
    index = search(list1, 6);
    printf("Índice de 6: %d\n", index);

    // Testando remoção por índice
    printf("\nRemovendo o elemento no índice 2 da lista 1...\n");
    remove_by_index(list1, 2);
    print_ordered_list(list1);

    // Testando remoção por valor
    printf("\nRemovendo o valor 4 da lista 1...\n");
    remove_by_value(list1, 4);
    print_ordered_list(list1);

    // Testando remoção do final
    printf("\nRemovendo o último elemento da lista 1...\n");
    remove_end(list1);
    print_ordered_list(list1);

    // Testando mesclagem de listas
    printf("\nInserindo elementos na lista 2...\n");
    insert(list2, 6);
    insert(list2, 7);
    insert(list2, 8);
    insert(list2, 9);
    insert(list2, 10);

    printf("Lista 2 após inserções:\n");
    print_ordered_list(list2);

    printf("\nMesclando lista 1 e lista 2...\n");
    t_ordered_list* merged_list = merge(list1, list2);
    printf("Lista mesclada:\n");
    print_ordered_list(merged_list);

    // Testando limpar a lista
    printf("\nLimpando lista 1...\n");
    clear(list1);
    printf("Lista 1 após limpar:\n");
    print_ordered_list(list1);

    // Liberando memória
    destroy_list(list1);
    destroy_list(list2);
    destroy_list(merged_list);

    return 0;
}
