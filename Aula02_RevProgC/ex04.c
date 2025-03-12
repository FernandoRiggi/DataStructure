#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
} t_ponto;

int main(int argc, char const *argv[]){
    t_ponto ponto_na_stack;
    ponto_na_stack.x = 2;
    ponto_na_stack.y = 5;    

    t_ponto* ponto_na_heap;
    ponto_na_heap = (t_ponto*) malloc(sizeof(t_ponto));
    ponto_na_heap->x; // (*ponto_na_heap).x = 10;
    ponto_na_heap->y; // (*ponto_na_heap).y = 8;
    
    printf("End. do ponto_na_stack: %p\n", &ponto_na_stack);
    printf("End. do ponto_na_heap: %p\n", &ponto_na_heap);
    printf("End. heap do ponto na heap: %p\n", ponto_na_heap);

    free(ponto_na_heap);

    return 0;
}
