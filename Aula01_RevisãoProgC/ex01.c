/*
Ler N
Imprime a soma de a N
(1+2+3+...+N)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    printf("Entre com o valor de N: ");
    scanf("%d",&N);
    int soma =0;
    for(int i=1; i<=N; i++){
        soma+=i; // n vezes -> O(n)
    }
    printf("\nA somatoria dos %d números é: %d", N, soma);

    soma = ((1+N)*N)/2;
    printf("%d\n", soma); // O(1)

    int somaPar =0;
    for(int i=1; i<=N; i++){
        if(i % 2 == 0){ // n vezes -> O(n)
            somaPar+=i;
        }
    }

    printf("\nA somatoria dos números pares é: %d\n", somaPar);

    somaPar = 0;
    for(int i =2; i<=N; i+=2){
        somaPar+=i; // n/2 vezs -> O(n)
    }

    return 0;
}