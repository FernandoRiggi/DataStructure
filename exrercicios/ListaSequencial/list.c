#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list* create_list(){
    t_list* list = (t_list*)malloc(sizeof(t_list));
    if(list == NULL) return NULL; //allocation failed

    list->max = 25; //default size
    list->size = 0;
    list->itens = (int*)malloc(sizeof(int)*list->max);
    if(list->itens == NULL) {
        free(list);
        return NULL; //allocation failed
    }
    return list;
}

int is_full(t_list* list){
    if(list->size >= list->max) return 1;
    return 0;
}

int is_empty(t_list* list){
    if(list->size == 0) return 1;
    return 0;
}

int double_size(t_list* list){
    if(list->size >= list->max){
        list->max *= 2;
        int* temp = (int*)realloc(list->itens, sizeof(int)*list->max);
        if(temp == NULL) return 0; //allocation failed
        list->itens = temp;
    }
    return 1;
}

t_list* append(int elem, t_list* list){
    if(is_full(list)){
        if(!double_size(list)) return NULL; //allocation failed
    }  
    list->itens[list->size] = elem;
    list->size++;
    return list;
}

t_list* insert(int elem, int index, t_list* list){
    if(is_full(list)){
        if(!double_size(list)) return NULL; //allocation failed
    }
    if(index < 0 || index > list->size) return NULL; //invalid index

    for(int i =list->size; i>index; i--){
        list->itens[i] = list->itens[i-1];
    }
    list->itens[index] = elem;
    list->size++;
    return list;
}

t_list* update(int elem, int index, t_list* list){
    if(index < 0 || index >= list->size) return NULL; //invalid index
    list->itens[index] = elem;
    return list;
}

t_list* remove_by_index(int index, t_list* list){
    if(is_empty(list)) return NULL; //LIST IS  EMPTY
    if(index < 0 || index >= list->size) return NULL; //invalid index
    for(int i = index; i<list->size -1; i++){
        list->itens[i] = list->itens[i+1];
    }
    list->size--;
    return list;
}

int remove_by_element(int elem, t_list* list){
    if(is_empty(list)) return 0; //list is empty
    int aux = 0;
    int find_elem = 0;
    for(int i =0; i<list->size; i++){
        if(list->itens[i] == elem){
            aux = i;
            find_elem = 1;
            break;
        }
    }
    if(find_elem==1){
        for(int i = aux; i<list->size -1; i++){
            list->itens[i] = list->itens[i+1];
        }
        list->size--;
        return 1;
    }    
    return 0;
}

int index_of(int elem, t_list* list){
    if(is_empty(list)) return -1; //list is empty
    
    for(int i =0; i<list->size; i++){
        if(list->itens[i] == elem) return i;
    }

    return -1;
}

int get(int index, t_list* list){
    if(is_empty(list)) return -1; //list is empty
    if(index < 0 || index >= list->size) return -1; //invalid index

    return list->itens[index];
}

int count(int elem, t_list* list){
    if(is_empty(list)) return 0; //list is empty
    
    int count = 0;
    for(int i = 0; i<list->size; i++){
        if(list->itens[i] == elem) count ++;
    }

    return count;
}

int size(t_list* list){
    if(list==NULL) return -1;
    return list->size;
}

t_list* clear(t_list* list){
    if(list==NULL) return NULL;

    list->size = 0;
    return list;
}

int is_sorted(t_list* list){
    if (list == NULL || list->size <= 1) return 1; // vazia ou 1 elem = ordenada
    int ascending = 1;
    int descending =1;

    for(int i=0; i<list->size -1 ; i++){
        if(list->itens[i] < list->itens[i+1]) ascending =0;
        if(list->itens[i] > list->itens[i+1]) descending =0;
    }

    if(ascending) return 1;
    if(descending) return -1;
    return 0;
}

t_list* copy_list(t_list* list){
    if(list==NULL) return NULL;
    t_list* new_list = create_list();
    if(new_list==NULL) return NULL;

    while(new_list->max < list->max){
        if (!double_size(new_list)) {
            free(new_list->itens);
            free(new_list);
            return NULL;
        }
    }

    for(int i =0; i<list->size; i++){
        new_list->itens[i] = list->itens[i];
    }

    new_list->size = list->size;

    return new_list;
}

t_list* copy_unique(t_list* list){
    if(list==NULL) return NULL;
    t_list* new_list = create_list();
    if(new_list==NULL) return NULL;

    while(new_list->max < list->max){
        if (!double_size(new_list)) {
            free(new_list->itens);
            free(new_list);
            return NULL;
        }
    }

    for(int i =0; i<list->size; i++){
        if(index_of(list->itens[i], new_list) == -1) append(list->itens[i], new_list);
    }

    return new_list;
}

t_list* inverted_new_list(t_list* list){
    if(list==NULL) return NULL;
    t_list* new_list = create_list();
    if(new_list==NULL) return NULL;

    while(new_list->max < list->max){
        if (!double_size(new_list)) {
            free(new_list->itens);
            free(new_list);
            return NULL;
        }
    }

    for(int i=list->size -1; i>=0; i--){
        append(list->itens[i], new_list);
    }  
    
    return new_list;
}

t_list* invert_list(t_list* list){
    if(list==NULL) return NULL;
    int i =0;
    int j = list->size-1;
    int aux;

    while(i<j){
        aux = list->itens[j];
        list->itens[j] = list->itens[i];
        list->itens[i] = aux;
        j--;
        i++;
    }

    return list;
}

t_list* merge(t_list* l1, t_list* l2){
    if(l1==NULL || l2==NULL) return NULL;
    if(is_empty(l1)) return copy_list(l1);
    if(is_empty(l2)) return copy_list(l2);
    t_list* new_list = create_list();
    int i=0, j=0;

    while(new_list->max < l1->max+l2->max){
        if(!double_size(new_list)){
            free(new_list->itens);
            free(new_list);
            return NULL;
        }
    }

    while(i < l1->size && j < l2->size){
        if(l1->itens[i] <= l2->itens[j]){
            append(l1->itens[i], new_list);
            i++;
        } else {
            append(l2->itens[j], new_list);
            j++;
        }
    }

    while(i < l1->size){
        append(l1->itens[i], new_list);
        i++;
    }

    while(j < l2->size){
        append(l2->itens[j], new_list);
        j++;
    }

    return new_list;
}

int remove_all_occurences(int elem, t_list* list){
    if (list == NULL || is_empty(list)) return 0;

    int total = count(elem, list);
    if(total<=0) return 0;

    for(int i=0;i<total;i++){
        remove_by_element(elem, list);
    }

    return total;
}