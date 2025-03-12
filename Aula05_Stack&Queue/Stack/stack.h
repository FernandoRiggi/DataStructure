#ifndef STACK_H
#define STACK_H

typedef struct {
    int max; //tamanho alocado
    int size; //número de elementos na lista
    int* items; //vetor com os elementos
} t_stack;

t_stack* create_stack(int);
int is_full(t_stack*);
int is_empty(t_stack*);
int size(t_stack*);
int push(t_stack*, int);
int pop(t_stack*, int*);
int top(t_stack*, int*);
void clear(t_stack*);
void destroy(t_stack*);

#endif