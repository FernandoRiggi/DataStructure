#ifndef LIST_H
#define LIST_H

typedef struct {
    int max; //tamanho alocado
    int size; //número de elementos na lista
    int* items; //vetor com os elementos
} t_list;

t_list* create_list(int);
void destroy_list(t_list*);
int is_full(t_list*);
int is_empty(t_list*);
int size(t_list*);
void clear(t_list*);
int search(t_list*, int);
int remove_last(t_list*);
int remove_by_index(t_list*, int);
int insert(t_list*, int, int);
int append(t_list*, int);
void print_list(t_list*);
int get(t_list*, int);

#endif