#include <stdio.h>

int main() {
    int n; // Índice do elemento que você deseja exibir
    int tamanho = 5; // Tamanho do vetor
    int vetor[5] = {10, 20, 30, 40, 50};

    printf("Digite o índice do elemento que você deseja exibir: ");
    scanf("%d", &n);

    // Verificar se o índice está dentro dos limites do vetor
    if (n >= 0 && n < tamanho) {
        int* ponteiro = &vetor[n]; // Obtém o endereço do elemento desejado

        printf("Elemento %d: %d\n", n, *ponteiro); // Exibe o valor do elemento
    } else {
        printf("Índice fora dos limites do vetor.\n");
    }

    return 0;
}
