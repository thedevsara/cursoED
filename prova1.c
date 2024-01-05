#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int item;
    struct No *prox;
    
}No;

int main(){

    //inicialização dos nós

    No *n1 = (No *)malloc(sizeof(No));
    n1-> item = 1;
    n1->prox = NULL;

    No *n2 = (No *)malloc(sizeof(No));
    n2->item = 4;
    n2->prox = NULL;

    No *n3 = (No *)malloc(sizeof(No));
    n3 -> item = 6;
    n3 -> prox = NULL;

    //encadeamento dos nos para criar a lista {n1, n2, NULL}
    n1->prox =n2;
    n2->prox = n3;
    n3->prox = NULL;



    //percorre os nós e imprime os itens da lista
    No *atual = n1;

    while(atual != NULL){
        printf("%d ", atual->item); // imprime o item do nó atual.
        atual = atual->prox; // move para o próximo nó.
    }

    //libera a memória alocada.
    free(n1);
    free(n2);

    return 0;
}