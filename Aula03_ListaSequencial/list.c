#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int max; //tamanho alocado
    int size; //número de elementos na lista
    int* items; //vetor com os elementos
} t_list;

t_list* create_list(int max){
    t_list* list = (t_list*) malloc(sizeof(t_list)); //alocando memória na heap
    list->max = max;
    list->size = 0;
    list->items = (int*) malloc(sizeof(int)* max);

    return list;
}

void destroy_list(t_list* list){
    free(list->items);
    free(list);
}

int is_full(t_list* list){
    return list->size >= list->max;
    // if(list->size>=list->max){
    //     return 1;
    // }
    // return 0;
}

int is_empty(t_list* list){
    return list->size <= 0;
}

int size(t_list* list){
    //retorna o tamanho da lista
    return list->size;
}

void clear(t_list* list){
    //esvazia a lista
    list-> size = 0;
}

int search(t_list* list, int elem){
    //busca determinado elemento
    if(is_empty(list)){
        return 0;
    }
    for(int i=0; i<size(list); i++){
        if(list->items[i]==elem){
            return i;
            break;
        }
    } return 0;
}

int remove_last(t_list* list){
    //remover do final
    if(is_empty(list)){
       return 0;
    }
    list->size--;
    return 1;
}

int remove_by_index(t_list* list, int indice){
    if(is_empty(list)){
        return 0;
    }
    for(int i=indice; i<size(list); i++){
        list->items[i] = list->items[i+1];
    }
    list->size--;
    return 1;
}

int insert(t_list* list, int elem, int indice){
    //insere elemento em determinada posição
    if(is_full(list)){
        return 0;
    }
    for(int i=size(list); i>=indice; i--){
        list->items[i+1] = list->items[i];
        if(i==indice){
            list->items[i] = elem;
        }
    }
    list->size++;
    return 1;
}

int append(t_list* list, int elem){
    if(is_full(list)){
        return 0;
    }
    list->items[list->size] = elem;
    list->size++;
    return 1;
}

void print_list(t_list* list){
    if(list->size != 0){
        printf("[ ");
        for(int i=0;i<list->size;i++){
            printf("%d, ", list->items[i]);
        }
        printf("]");
        printf("\n");
    }
}

int get(t_list* list, int index){
    //Retorna o elemento que está na posição “index” da lista.
    if(is_empty(list)) return 0;
    if(index>size(list)) return 0;
    return list->items[index];
}

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
