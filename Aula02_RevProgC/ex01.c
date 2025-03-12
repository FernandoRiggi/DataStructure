#include <stdio.h>

void swap(int* x, int* y){
    int aux=*x;
    *x = *y;
    *y = aux;
}

int main(int argc, char const *argv[]){
    int x = 5, y = 10;
    printf("Antes: %d %d\n", x, y);
    swap(&x, &y);
    printf("Depois: %d %d\n", x, y);
    return 0;
}
