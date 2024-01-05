#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pecas;
    float preco;

}Venda;

void imprimirTotal(Venda v1, Venda v2) {

    Venda total = {0, 0.0};
    total.pecas = v1.pecas + v2.pecas;
    total.preco = v1.preco + v2.preco;
    printf("Total de peças: %d\n", total.pecas); 
    printf("Preço das peças: R$%.2f\n", total.preco);

}


int main() {

    Venda v1 = {1,20}, v2 = {3,10};
    imprimirTotal(v1,v2);
    return 0;
}