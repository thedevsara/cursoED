#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int *v;

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &n);


    //aloca dinamicamente a memória para o vetor;
    v = (int*)malloc(n * sizeof(int));

    if(v==NULL){
        printf("Erro!\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        v[i] = 100 * i;
    }


        printf("Valores do vetor:");
        for(int i=0; i<n; i++){
            printf("v[%d] = %d\n", i, v[i]);
        }

            free(v);

            return 0;

    }
