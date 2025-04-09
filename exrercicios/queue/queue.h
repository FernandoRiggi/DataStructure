#ifndef STACK_H
#define STACK_H

typedef struct t_queue{
    int max;
    int size;
    int front;
    int rear;
    int* itens;
}t_queue;

t_queue* create_queue();
int is_empty(t_queue* queue);
int is_full(t_queue* queue);
t_queue* in(t_queue* queue, int elem);
int out(t_queue* queue, int* elem);
int top(t_queue* queue, int* elem);
int size(t_queue* queue);
void clear(t_queue* queue);
void destroy(t_queue* queue);
#endif