#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Fila {
    int itens[MAX_SIZE];
    int frente, tras;
};

void inicializar(struct Fila* fila) {
    fila->frente = -1;
    fila->tras = -1;
}

int filaVazia(struct Fila* fila) {
    return fila->frente == -1;
}

int filaCheia(struct Fila* fila) {
    return (fila->tras+1) % MAX_SIZE == fila->frente;

}

void entrar(struct Fila* fila, int valor) {
    if(filaCheia(fila)) {
        printf("FILA CHEIA.\n");
        exit(EXIT_FAILURE);
    }

    if(filaVazia(fila)) {
        fila->frente =0;
    }

    fila->tras = (fila->tras + 1) % MAX_SIZE;
    fila->itens[fila->tras] = valor;

}

int sair(struct Fila* fila) {
    if(filaVazia(fila)) {
        printf("FILA VAZIA!");
        exit(EXIT_FAILURE);

    }

    int valor = fila->itens[fila->frente];

    if(fila->frente == fila->tras) {
        inicializar(fila);
    }else{
        fila->frente = (fila->frente + 1) % MAX_SIZE;
    }

    return valor;
}

int primeiro(struct Fila* fila) {
    if(filaVazia(fila)) {
        printf("FILA VAZIA.");
        exit(EXIT_FAILURE);
    }
    return fila->itens[fila->frente];
}

int ultimo(struct Fila *fila) {
    if(filaVazia(fila)) {
        printf("FILA VAZIA.");
        exit(EXIT_FAILURE);

    }

    return fila->itens[fila->tras];
}

void empilhar(struct Fila* fila1, struct Fila* fila2, int valor) {
    entrar(fila1, valor);
}

int desempilhar(struct Fila* fila1,struct Fila* fila2){
    while(fila1->frente != fila1->tras){
        entrar(fila2, sair(fila1));
    }
    
    int valorDesempilhado = sair(fila1);

    while(!filaVazia(fila2)){
        entrar(fila1, sair(fila2));
    }
    return valorDesempilhado;

}

int main() {

    struct Fila fila1, fila2;
    inicializar(&fila1);
    inicializar(&fila2);

    empilhar(&fila1, &fila2, 1);
    empilhar(&fila1, &fila2, 2);
    empilhar(&fila1, &fila2, 3);

    printf("Elemento desempilhado: %d\n", desempilhar(&fila1, &fila2));
    printf("Elemento desempilhado: %d\n", desempilhar(&fila1, &fila2));

    empilhar(&fila1, &fila2, 4);

    printf("Elemento desempilhado: %d\n", desempilhar(&fila1, &fila2));
    printf("Elemento desempilhado: %d\n", desempilhar(&fila1, &fila2));




    return 0;
}





