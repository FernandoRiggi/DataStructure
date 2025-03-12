#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* create_stack(int max)
{
    t_stack *stack = (t_stack*)malloc(sizeof(t_stack)); // alocando memória na heap
    stack->max = max;
    stack->size = 0;
    stack->items = (int *)malloc(sizeof(int) * max);

    return stack;
}

int is_full(t_stack* stack)
{
    return stack->size >= stack->max;
}

int is_empty(t_stack* stack)
{
    return stack->size <= 0;
}

int size(t_stack* stack)
{
    return stack->size;
}

int push(t_stack* stack, int value)
{
    if (is_full(stack))
    {
        stack->items = (int *)realloc(stack->items, sizeof(int) * stack->max * 2);

        if (stack->items == NULL)
            return 0;

        stack->max *= 2;
    }

    stack->items[size(stack)] = value;
    stack->size++;
    return 1;
}

int pop(t_stack* stack, int* elem){
    if(is_empty(stack)) return 0;
    *elem = stack->items[size(stack)-1];
    stack->size --;
    return 1;   
}

int top(t_stack* stack, int* value){
    if(is_empty(stack)) return 0;

    *value = stack->items[size(stack)-1];
    return 1;
}

void clear(t_stack* stack){
    stack->size =0;
}

void destroy(t_stack* stack){
    free(stack->items);
    free(stack);
}