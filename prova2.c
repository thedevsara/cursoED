#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No *prox;

}No;

int main() {

    No* n1 = (No *)malloc(sizeof(No));
    n1->item = 10;
    n1->prox = NULL;

    No *n2 = (No *)malloc(sizeof(No));
    n2 ->item = 3;
    n2 ->prox = NULL;

    No *n3 = (No *)malloc(sizeof(No));
    n3 ->item = 4;
    n3 ->prox = NULL;

    if(n1->item > n2->item) {
        No* temp = n1;
        n1 = n2;
        n2 = temp;
    }

    if(n2->item > n3->item) {
        No* temp = n2;
        n2 = n3;
        n3 = temp;
    }
    
    n1->prox = n2;
    n2->prox = n3;
    n3->prox = NULL;

    No* atual = n1;

    while(atual != NULL){
        printf("%d ", atual->item);
        atual = atual->prox;

    }

    free(n1);
    free(n2);
    free(n3);


    return 0;
}
