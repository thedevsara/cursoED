#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    char letra[1];
    struct lista* prox;
} Lista;

Lista* novo = NULL;
Lista* inicio = NULL;
Lista* fim;
Lista* atual;
Lista* anterior;

void inserirLetraFinal();
void mostrar();

int main() {
    int cont;
    char l[1];
    do {
        printf("\n\n1 - Inserir Letra no Final da Lista ");
        printf("\n2 - Mostrar letras ");
        printf("\n3 - Sair ");
        printf("\nDigite a Opcao Desejada: ");
        scanf("%d", &cont);
        switch (cont) {
            case 1:
                printf("Digite uma letra: ");
                fflush(stdin);
                gets(l);
                novo = (Lista*)malloc(sizeof(Lista));
                novo->prox = NULL;
                novo->letra[0] = l[0]; // Store the character in the structure
                inserirLetraFinal();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida! Tente de novo! ");
        }
    } while (cont != 3);
}

// Insert at the END of the list
void inserirLetraFinal() {
    if (inicio == NULL) {
        inicio = novo;
        fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }
}

void mostrar() {
    atual = inicio;
    while (atual != NULL) {
        printf("%c ", atual->letra[0]);
        atual = atual->prox;
    }
    printf("\n");
}
