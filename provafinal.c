#include <stdio.h>
#include <string.h>

struct livro {
    int cod;
    char nome[20];
};
typedef struct livro Tlivro;

Tlivro livros[5];
int ultimo = 0;

void inserirInicio(Tlivro novo) {
    if (ultimo < 5) {
        for (int i = ultimo; i > 0; i--) {
            livros[i] = livros[i - 1];
        }
        livros[0] = novo;
        ultimo++;
    } else {
        printf("\nBiblioteca lotada!!!");
    }
}

void inserirNoFinal(Tlivro novo) {
    if (ultimo < 5) {
        livros[ultimo] = novo;
        ultimo++;
    } else {
        printf("\nBiblioteca lotada!!!");
    }
}

int buscar(int codigo) {
    for (int i = 0; i < ultimo; i++) {
        if (livros[i].cod == codigo) {
            printf("\nLivro encontrado - Código: %d, Nome: %s\n", livros[i].cod, livros[i].nome);
            return i;
        }
    }
    return -1;
}

void mostra() {
    for (int i = 0; i < ultimo; i++) {
        printf("\nCodigo do livro: %d", livros[i].cod);
        printf("\nNome do livro: %s", livros[i].nome);
    }
}

int main() {
    int escolha;
    Tlivro novoLivro;
    int codigoBusca;

    while (1) {
        printf("\n-----------BIBLIOTECA IFPI------------\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Buscar livro por código\n");
        printf("4. Mostrar lista\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o código do livro: ");
                scanf("%d", &novoLivro.cod);
                printf("Digite o nome do livro: ");
                scanf("%s", novoLivro.nome);
                inserirInicio(novoLivro);
                break;
            case 2:
                printf("Digite o código do livro: ");
                scanf("%d", &novoLivro.cod);
                printf("Digite o nome do livro: ");
                scanf("%s", novoLivro.nome);
                inserirNoFinal(novoLivro);
                break;
            case 3:
                printf("Digite o código a ser buscado: ");
                scanf("%d", &codigoBusca);
                int posicao = buscar(codigoBusca);
                if (posicao != -1) {
                    printf("Livro encontrado na posição: %d\n", posicao);
                } else {
                    printf("\nLivro não encontrado.\n");
                }
                break;
            case 4:
                mostra();
                break;
            case 5:
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
