#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* create_stack(){
    t_stack* stack = (t_stack*)malloc(sizeof(t_stack));
    if(stack==NULL) return NULL; //FAILED ALLOCATION

    stack->max=25;
    stack->size=0;
    stack->itens = (int*)malloc(sizeof(int)*stack->max);
    if(stack->itens == NULL){
        free(stack);
        return NULL; // allocation fallied
    }
    return stack;
}

int size(t_stack* stack){
    return stack->size;
}

int is_full(t_stack* stack){
    if(stack==NULL) return -1;
    return (stack->size == stack->max);
}

int is_empty(t_stack* stack){
    if(stack==NULL) return 1;
    return (stack->size == 0);
}

int double_size(t_stack* stack){
    if(stack->size>=stack->max){
        stack->max*=2;
        int* temp = (int*)realloc(stack->itens, sizeof(int)*stack->max);
        if(temp==NULL) return -1; //
        stack->itens = temp;
    }

    return 1;
}

t_stack* push(t_stack* stack, int elem){
    if(stack==NULL) return NULL;
    if(is_full(stack)){
         if(double_size(stack)==-1) return NULL;
    }

    stack->itens[stack->size] = elem;
    stack->size++;
    return stack;
}

int pop(t_stack* stack, int* value){
    if(stack==NULL || is_empty(stack)) return 0;

    *value = stack->itens[stack->size-1];
    stack->size--;
    return 1; 
}

int top(t_stack* stack, int*value){
    if(stack==NULL || is_empty(stack)) return 0;

    *value = stack->itens[stack->size-1];
    return 1;
}

void clear(t_stack* stack){
    if(stack==NULL) return;
    stack->size = 0;
}

void destroy(t_stack* stack){
    if(stack==NULL) return;
    
    free(stack->itens);
    free(stack);
}