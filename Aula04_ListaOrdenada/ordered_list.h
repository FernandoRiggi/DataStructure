#ifndef LIST_ORDERED_H
#define LIST_ORDERED_H

typedef struct {
    int max; //tamanho alocado
    int size; //número de elementos na lista
    int* items; //vetor com os elementos
} t_ordered_list;

t_ordered_list* create_list(int);
void destroy_list(t_ordered_list*);
int is_full(t_ordered_list*);
int is_empty(t_ordered_list*);
int size(t_ordered_list*);
void clear(t_ordered_list*);
int search(t_ordered_list*, int);
int remove_by_index(t_ordered_list*,int);
int remove_by_value(t_ordered_list*,int);
int remove_end(t_ordered_list*);
int insert(t_ordered_list*,int);
t_ordered_list* merge(t_ordered_list*,t_ordered_list*);
void print_ordered_list(t_ordered_list*);

#endif