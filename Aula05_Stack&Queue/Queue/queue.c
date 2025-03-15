#include <stdio.h> 
#include <stdlib.h>
#include "queue.h"

t_queue* create_queue(int max){
    t_queue* queue = (t_queue*)malloc(sizeof(t_queue));
    queue->max = max;
    queue->size = 0;
    queue->items = (int*)malloc(sizeof(int) * max);

    return queue;
}

int is_full(t_queue* queue){
    return queue->size >= queue->max;
}

int is_empty(t_queue* queue){
    return queue->size <=0;
}

int size(t_queue* queue){
    return queue->size;
}

