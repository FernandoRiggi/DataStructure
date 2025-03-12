#include <stdio.h>

int main(){
    int vetor[] = {1, 3, 5, 3, 8, 20, 15, 10};
    int n = 8;

    int repetido = 0; // boolean
    // verificar se o vetor contem repetição
    for(int i=0; i<n-1 && !repetido; i++){
        for(int j=i+1; j<n; j++){
            if(vetor[i]==vetor[j] && i!=j){ // (n²-n)/2 -> O(n²)
                repetido = 1;
            }
        }
    }

    printf("%d\n", repetido);
    return 0;
}