#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){
    int linhas = 1420;
    int colunas = linhas;

    int** matriz;
    matriz = (int**) malloc(sizeof(int*) * linhas);
    for(int i=0; i<linhas; i++){
        matriz[i] = (int*) malloc(sizeof(int) * colunas);
    }

    for(int i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
