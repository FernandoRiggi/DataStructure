#include <stdio.h>

int main(int argc, char const *argv[]){
    int vetor_estatico[5];

    int n;
    scanf("%d", &n);
    int vetor_vla[n];

    printf("%d\n", vetor_estatico[2]);
    printf("%p\n", &(vetor_estatico[2]));

    printf("%d\n",vetor_estatico[5]);
    printf("%ld\n", &(vetor_estatico[0]));
    printf("%ld\n",&n);

    return 0;
}
