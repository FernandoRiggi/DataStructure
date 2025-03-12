#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    
    int* vetor_dinamico ;

    vetor_dinamico = (int *) malloc(sizeof(int) * n);
    // vetor_dinamico = (int *) calloc(sizeof(int), n);
    vetor_dinamico[3] = 10;

    // *(vetor_dinamico+3); <-> vetor_dinamico[3];

    free(vetor_dinamico);

    return 0;
}