#include<stdio.h>
#include"list.h"

int main(int argc, char const *argv[]){
    //declarar lista
    t_list* list;

    //criar uma lista
    list = create_list(10);

    //adicionar alguns elementos
    append(list, 5);
    append(list, 10);
    insert(list, 3, 1);
    append(list, 8);
    //imprimir a lista
    print_list(list);
    remove_last(list);
    print_list(list);
    remove_by_index(list, 0);
    print_list(list);
    printf("%d", get(list, 0));

    //procurar elemento
    int procurar = search(list, 10);
    //liberar memoria
    destroy_list(list);

    return 0;
}
