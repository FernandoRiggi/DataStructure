#ifndef QUEUE_H
#define QUEUE_h

typedef struct {
    int max; //tamanho alocado
    int size; //número de elementos na lista
    int* items; //vetor com os elementos
} t_queue;

#endif