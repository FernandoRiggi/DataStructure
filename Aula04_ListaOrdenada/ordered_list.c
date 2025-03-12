#include<stdio.h>
#include<stdlib.h>
#include"ordered_list.h"

t_ordered_list* create_list(int max){
    t_ordered_list* list = (t_ordered_list*) malloc(sizeof(t_ordered_list)); //alocando memória na heap
    list->max = max;
    list->size = 0;
    list->items = (int*) malloc(sizeof(int)* max);

    return list;
}

void destroy_list(t_ordered_list* list){
    free(list->items);
    free(list);
}

int is_full(t_ordered_list* list){
    return list->size >= list->max;
}

int is_empty(t_ordered_list* list){
    return list->size <= 0;
}

int size(t_ordered_list* list){
    return list->size;
}

void clear(t_ordered_list* list){
    list-> size = 0;
}

int search(t_ordered_list* list, int elem){
    if(is_empty(list)){
        return -1;
    }
    int inicio = 0;
    int final = list->size-1;
    int meio;
    while(inicio <= final){
        meio = inicio + (final - inicio)/2;
        if(list->items[meio] == elem){
            return meio;
        }
        if(list->items[meio] > elem){
            final = meio-1;
        }
        if(list->items[meio] < elem){
            inicio = meio+1;
        }
    }
    return -1;
}

int remove_by_index(t_ordered_list* list, int indice){
    if(is_empty(list)){
        return 0;
    }
    for(int i=indice; i<size(list)-1; i++){
        list->items[i] = list->items[i+1];
    }
    list->size--;
    return 1;
}

int remove_by_value(t_ordered_list* list, int value){
    int x;
    if(is_empty(list)){
        return 0;
    }
    for(int i; i<size(list);i++){
        if(list->items[i]==value){
            x = i;
            break;
        }
    }
    if(x==size(list)){
        return 0;
    }

    for(int j = x; j<size(list)-1; j++){
        list->items[j] = list->items[j+1];
    }
    list->size--;
    return 1;
}

int remove_end(t_ordered_list* list){
    if(is_empty(list)){
       return 0;
    }
    list->size--;
    return 1;
}

int insert(t_ordered_list* list, int value){
    if(is_full(list)){
        list->items = (int*) realloc(list->items, sizeof(int) * list->max * 2);
    
        if(list->items ==NULL){
            return 0;
        }
        list->max *= 2;
    }
    if(is_empty(list)){
        list->items[size(list)] = value;
        list->size++;
        return 1;
    }

    int i = size(list)-1;

    while(i>=0 && list->items[i]>value){
        list->items[i+1] = list->items[i];
        i--;
    }

    list->items[i+1]=value;
    list->size++;
    return 1;
}
t_ordered_list* merge(t_ordered_list* list1, t_ordered_list* list2){
    int i = 0, j = 0, x = 0;
    if(is_empty(list1) && !is_empty(list2)) return list2;
    if(is_empty(list2) && !is_empty(list1)) return list1;
    if(is_empty(list1) && is_empty(list2)) return NULL;

    t_ordered_list* lista_final = create_list(list1->size+list2->size);

    while(i < list1->size && j < list2->size){
        if(list1->items[i] >= list2->items[j]){
            lista_final->items[x] = list2->items[j];
            j++;
        }
        else{
            lista_final->items[x] = list1->items[i];
            i++;
        }
        x++;
    }
    while(i < list1->size){
        lista_final->items[x] = list1->items[i++];
        x++;
    }
    while(j < list2->size){
        lista_final->items[x] = list2->items[j++];
        x++;
    }
    lista_final->size = x;
    return lista_final;
}
void print_ordered_list(t_ordered_list* list){
    if(list->size != 0){
        printf("[ ");
        for(int i=0;i<list->size;i++){
            printf("%d, ", list->items[i]);
            if(i <list->size-1){
                printf(", ");
            }
        }
        printf(" ]\n");
    }
}