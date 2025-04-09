#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

t_linked_list* create_list() {
    t_linked_list* linked_list = (t_linked_list*)malloc(sizeof(t_linked_list));
    linked_list->size = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
}

int is_empty(t_linked_list* linked_list){
    return linked_list->size == 0;
}

void clear(t_linked_list* linked_list){
    linked_list->size = 0;
}

void destroy(t_linked_list* linked_list){
    t_node* node = linked_list->head;
    while(node!=NULL){
        t_node* aux = node;
        node = node->next;
        free(aux->item);
        free(aux);
    }
    free(linked_list);
}

void append(t_linked_list* linked_list, int item){
    t_node* node = malloc(sizeof(t_node));
    node->item = item;
    node->next = NULL;

    if(is_empty(linked_list)){
        linked_list->head = node;
    } else{
        linked_list->tail->next = node;
    }

    linked_list->tail = node;
    linked_list->size++;
}

int remove_item(t_linked_list* linked_list, int item){
    if(linked_list==NULL || linked_list->head==NULL) return -1;

    t_node* aux = linked_list->head;
    t_node* aux2 = NULL;

    if(aux->item == item){
        linked_list->head = aux->next;
        int valor = aux->item;
        free(aux);
        linked_list->size--;
        return valor;
    }

    while(aux!=NULL && aux->item!=item){
        aux2 = aux;
        aux = aux->next;
    }

    if(aux==NULL) return -1;

    aux2->next = aux->next;
    int valor = aux->item;
    free(aux);
    linked_list->size--;
    return valor;     
}

int remove_at(t_linked_list* linked_list, int index){
    if(linked_list==NULL || linked_list->head==NULL) return -1;

    t_node* aux = linked_list->head;
    t_node* aux2 = NULL;
    int count = 0;

    if(index==0){
        linked_list->head = aux->next;
        int item = aux->item;
        free(aux);
        return item;
    }
    
    while(aux!=NULL && count<index){
        aux2=aux;
        aux = aux->next;
        count++;
    }

    if(aux==NULL) return -1;

    aux2->next= aux->next;
    int item = aux->item;
    free(aux);
    return item;
}

void insert(t_linked_list* linked_list, int index, int item){
    if(index<0 || index > linked_list->size) return;

    t_node* node = malloc(sizeof(t_node));
    node->item = item;
    
    if(index==0){
        node->next = linked_list->head;
        linked_list->head = node;
    } else{
        t_node* aux = linked_list->head;
        for(int count =0; count< index -1; count++){
            aux = aux->next;
        }

        if(aux!=NULL){
            node->next = aux->next;
            aux->next = node;
        }
    }
    
    linked_list->size++;
}

void sort(t_linked_list* linked_list){
    if(linked_list==NULL|| linked_list->head==NULL) return;

    int trocado;
    t_node* aux;
    t_node* ultimo = NULL;
    do{
        trocado =0;
        aux = linked_list->head;

        while (aux->next!=ultimo){
            if(aux->item > aux->next->item){
                int temp = aux->item;
                aux->item = aux->next->item;
                aux->next->item = temp; 
                trocado = 1;
            }
            aux = aux->next;
        }
        ultimo = aux;
    } while(trocado);
}

void print_list(t_linked_list* linked_list){
    t_node* aux = linked_list->head;
    printf("[ ");
    while (aux->next!=NULL)
    {
        printf("%d ", aux->item);
        aux = aux->next;
    }
    printf("]");
}

//append sem o tail
// void append(t_linked_list* linked_list, int item) {
//     t_node* node = malloc(sizeof(t_node));
//     node->item = item;
//     node->next = NULL; 
//     if(is_empty(linked_list)){
//         linked_list->head=node;
//     } else{
//         t_node* aux = linked_list->head;
//         while(aux->next != NULL){
//             aux = aux->next;
//         }
//         aux->next = node;
//     }
//     linked_list->size++;
// }