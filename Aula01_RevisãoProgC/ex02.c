#include <stdio.h>

int main(){
    int vetor[] = {1, 3, 5, 3, 8, 20, 15, 10};
    int n = 8;

    int ordenado = 1;
    // verificar se o vetor esta ordenado de forma crescente
    int i =0;
    while(i<n-1){
        if(vetor[i+1]<vetor[i]){ //n-1 vezes -> O(n)
            ordenado=0;
            break;
        }
        i++;
    }

    printf("%d\n", ordenado);

    return 0;
}