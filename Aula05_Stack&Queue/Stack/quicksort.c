#include <stdio.h>
#include "quicksort.h"
#include "stack.h"

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;

    for(int j = low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort_iterative(int arr[], int n){
    t_stack* stack = create_stack(n);
    int low = 0, high = n-1;
    push(stack, low);
    push(stack, high);

    while(!is_empty(stack)){
        pop(stack, &high);
        pop(stack, &low);
        
        int pivot = partition(arr, low, high);

        if(pivot-1>low){
            push(stack, low);
            push(stack, pivot-1);
        }
        if(pivot+1<high){
            push(stack, pivot+1);
            push(stack, high);
        }
    }

    destroy(stack);
}
