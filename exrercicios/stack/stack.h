#ifndef STACK_H
#define STACK_H

typedef struct t_stack{
    int max;
    int size;
    int* itens;
}t_stack;

t_stack* create_stack();
int size(t_stack* stack);
int is_full(t_stack* stack);
int is_empty(t_stack* stack);
int double_size(t_stack* stack);
t_stack* push(t_stack* stack, int elem);
int pop(t_stack* stack, int* value);
int top(t_stack* stack, int* value);
void clear(t_stack* stack);
void destroy(t_stack* stack);
#endif