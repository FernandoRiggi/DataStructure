#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

t_list* create_list(){
    t_list* list = (t_list*)malloc(sizeof(t_list));
    if(list==NULL) return NULL; //ALLOCATION FAILED

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void destroy_list(t_list* list){
    if(list==NULL) return;

    t_node* current = list->head;
    t_node* next;

    while(current!=NULL){
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int size(t_list* list){
    if(list==NULL) return -1;

    return list->size;
}

int is_empty(t_list* list){
    if(list==NULL) return -1;
    
    return (list->size == 0);
}

int append(t_list* list, int elem){
    if(list == NULL) return -1;

    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    if(new_node==NULL) return -1; //allocation failed

    new_node->item = elem;
    new_node->next = NULL;

    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }else{
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;

    return 1;
}

int insert(t_list *list, int index, int elem){
    if (list == NULL || index < 0 || index > list->size) return 0;

    if(index==list->size) return append(list, elem);

    t_node* new_node = (t_node*)malloc(sizeof(t_node));
    if(new_node == NULL) return -1; //allocation failed

    new_node->item = elem;
    new_node->next = NULL;

    if(index==0){
        new_node->next = list->head;
        list->head = new_node;
        if(list->size==0) list->tail = new_node;
    }else{
        t_node* current = list->head;
        for(int i=0; i<index-1; i++){
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }

    list->size++;
    return 1;
}

int remove_item(t_list *list, int item){
    if(list==NULL) return -1;
    if(is_empty(list)) return 1;

    t_node* current = list->head;
    t_node* prev = NULL;

    while(current!=NULL && current->item!=item){
        prev = current;
        current = current->next;
    }

    if(current==NULL) return 0;
    
    if(prev==NULL){
        list->head = current->next;
        if(list->head == NULL) list->tail = NULL;
    }else{
        prev->next = current->next;
        if(current==list->tail) list->tail = prev;
    }

    free(current);
    list->size--;
    return 1;
}

t_node* get_node_item(t_list *list, int item){
    if(list==NULL || is_empty(list)) return NULL;

    t_node* current = list->head;

    while(current!=NULL && current->item!=item){
        current = current->next;
    }

    return(current);
}

t_node* get_item_by_index(t_list *list, int index){
    if (list == NULL || index < 0 || index >= list->size) return 0;

    t_node* current = list->head;

    for(int i=0; i<index; i++){
        current = current->next;
    }

    return current;
}

void print_list(t_list *list){
    if(list==NULL || is_empty(list)) return;

    t_node* current = list->head;

    while(current!=NULL){
        printf("%d ", current->item);
        current = current->next;
    }

    printf("\n");
}

void clear(t_list *list){
    if(list==NULL || is_empty(list)) return;

    t_node* current = list->head;
    t_node* next;

    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }

    list->head=NULL;
    list->tail=NULL;
    list->size = 0;
}

int find(t_list *list, int item){
    if(list==NULL || is_empty(list)) return 0;

    t_node* current = list->head;

    while(current!=NULL && current->item!=item){
        if(current->item==item) return 1;
        current=current->next;
    }

    return 0;
}

int remove_at(t_list *list, int index){
    if (list == NULL || index < 0 || index >= list->size) return 0;

    t_node* current = list->head;
    t_node* prev = NULL;

    for(int i=0; i<index; i++){
        prev = current;
        current = current->next;
    }

    if(prev==NULL){
        list->head = current->next;
        if(list->head == NULL) list->tail = NULL;
    } else{
        prev->next = current->next;
        if(current==list->tail) list->tail = prev;
    }

    free(current);
    list->size--;
    return 1;
}

t_node* peek_front(t_list* list){
    if(list==NULL || is_empty(list)) return NULL;

    return list->head;
}

t_node* peek_back(t_list* list){
    if(list==NULL || is_empty(list)) return NULL;

    return list->tail;
}

t_node* pop_front(t_list *list){
    if(list==NULL || is_empty(list)) return NULL;

    t_node* removed = list->head;
    list->head = removed->next;

    if(list->head==NULL){
        list->tail = NULL;
    }

    list->size--;
    removed->next = NULL;

    return removed;
}

t_node* pop_back(t_list *list){
    if(list==NULL || is_empty(list)) return NULL;

    t_node* removed = list->tail;
    
    if(list->head == list->tail){
        list->head = NULL;
        list->tail =NULL;
    }else{
        t_node* current = list->head;
        while(current->next!=list->tail){
            current = current->next;
        }

        current->next = NULL;
        list->tail = current;
    }

    list->size--;
    removed->next = NULL;

    return removed;
}

int reverse(t_list *list){
    if(list == NULL || is_empty(list)) return 0;

    t_node* current = list->head;
    t_node* prev = NULL;
    t_node* next = NULL;

    list->tail = list->head;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    list->head = prev;

    return 1;
}

int sort(t_list *list){
    if(list == NULL || is_empty(list)) return 0;

    t_node* current;
    t_node* end = NULL;
    int swapped;

    do{
        swapped=0;
        current = list->head;

        while(current->next != end){
            if(current->item > current->next->item){
                int temp = current->item;
                current->item = current->next->item;
                current->next->item = temp;
                swapped = 1;
            }
            current = current->next;
        }
        end = current;
    }while(swapped);
  
    return 1;
}

t_list* merge(t_list *list1, t_list *list2){
    if ((list1 == NULL || is_empty(list1)) && (list2 == NULL || is_empty(list2))) return NULL;    
    
    t_list* merged = create_list();
    if(merged==NULL) return NULL;

    t_node* current_list1 = list1 ? list1->head : NULL;
    t_node* current_list2 = list2 ? list2->head : NULL;

    while(current_list1!=NULL && current_list2!=NULL){
        if(current_list1->item <= current_list2->item){
            append(merged, current_list1->item);
            current_list1 = current_list1->next;
        }else{
            append(merged, current_list2->item);
            current_list2 = current_list2->next;
        }
    }

    while(current_list1!=NULL){
        append(merged, current_list1->item);
        current_list1 = current_list1->next;
    }

    while(current_list2!=NULL){
        append(merged, current_list2->item);
        current_list2= current_list2->next;
    }

    return merged;
}

int clone(t_list *src, t_list *dest){
    if(src == NULL || is_empty(src) || dest==NULL) return 0;
    clear(dest);

    t_node* current = src->head;

    while(current!=NULL){
        append(dest, current->item);
        current = current->next;
    }

    return 1;
}
