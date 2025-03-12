#include<stdio.h>
#include<stdlib.h>
#include"list.h"


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
}

int is_empty(t_list* list){
    return list->size <= 0;
}

int size(t_list* list){
    return list->size;
}

void clear(t_list* list){
    list-> size = 0;
}

int search(t_list* list, int elem){
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
    if(is_empty(list)) return 0;
    if(index>size(list)) return 0;
    return list->items[index];
}