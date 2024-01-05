#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrututura pessoa
typedef struct Pessoa {

    int cpf;
    char nome[50];
    struct Pessoa *prox;
   

}Pessoa;

int main() {

    //INICIALIZAÇÃO 
    Pessoa* p1 = (Pessoa*)malloc(sizeof(Pessoa));
    p1->cpf = 1111;
    strcpy(p1->nome, "Sara");
    p1->prox = NULL;

    Pessoa* p2 =(Pessoa*)malloc(sizeof(Pessoa));
    p2->cpf = 2222;
    strcpy(p2->nome, "Katia");
    p2->prox = NULL;

    Pessoa* p3 =(Pessoa*)malloc(sizeof(Pessoa));
    p3->cpf = 4444;
    strcpy(p3->nome, "Jonatas");
    p3->prox = NULL;

    //encadeamento para criar a lista ordenada por CPF
    if(p1->cpf > p2->cpf) {
        Pessoa* temp = p1;
        p1 = p2;
        p2 = temp;
    }

    if(p2->cpf > p3->cpf) {
        Pessoa* temp = p2;
        p2 = p3;
        p3 = temp;

    }

    if(p1->cpf > p2->cpf) {
        Pessoa* temp = p1;
        p1 = p2;
        p2 = temp;
    }

    //conecta as pessoas na ordem correta
    p3->prox = p1;
    p1->prox = p2;


    //percorre a lista e imprime os nomes na ordem
    Pessoa* atual = p3;

    while(atual != NULL) {
        printf("CPF: %d, NOME: %s\n", atual->cpf, atual->nome);
        atual = atual ->prox;
    }
    //libera memÓria alocada
    free(p1);
    free(p2);
    free(p3);

    return 0;
}


