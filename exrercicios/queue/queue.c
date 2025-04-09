#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

t_queue* create_queue(){
    t_queue* queue = (t_queue*)malloc(sizeof(t_queue));
    if(queue == NULL) return NULL; //allocation failed

    queue->max = 100;
    queue->size =0;
    queue->front =0;
    queue->rear = 0;
    queue->itens = (int*)malloc(sizeof(int)*queue->max);
    if(queue->itens==NULL){
        free(queue);
        return NULL; //allocation failed
    }
    return queue;
}

int is_empty(t_queue* queue){
    if(queue==NULL) return 1;
    return(queue->size==0);
}

int is_full(t_queue* queue){
    if(queue==NULL) return 0;
    return(queue->size == queue->max);
}

t_queue* in(t_queue* queue, int elem){
    if(queue==NULL) return NULL;
    if(is_full(queue)) return NULL;

    queue->itens[queue->rear] = elem;
    queue->rear = (queue->rear + 1) % queue->max;
    queue->size++;

    return queue;
}

int out(t_queue* queue, int* elem){
    if(queue==NULL || is_empty(queue)) return 0;
    
    *elem = queue->itens[queue->front];
    queue->front = (queue->front+1) % queue->max;
    queue->size--;
    return 1;
}

int top(t_queue* queue, int* elem){
    if(is_empty(queue) || queue==NULL) return 0;
    
    *elem=queue->itens[queue->front];
    return 1;
}

int size(t_queue* queue){
    if(queue==NULL) return -1;

    return queue->size;
}

void clear(t_queue* queue){
    if(queue==NULL) return;

    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
}

void destroy(t_queue* queue){
    if(queue==NULL) return;
    free(queue->itens);
    free(queue);
}