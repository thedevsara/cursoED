#include <stdio.h> //entrada e saída de dados;
#include <stdlib.h> //alocação de memória;

typedef struct no {
    int cod;
    char nome[20];

}No;

void incluir(No novo, No vetor[], int *posicao){
    if(*posicao <10){
        vetor[*posicao] = novo;
        (*posicao)++;
        printf("Elemento incluído com sucesso!\n");
    }else{
        printf("O vetor está cheio!\n");
    }
}

    int procura(int ide , No vetor[], int posicao){
        for(int i=0; i<posicao; i++){
            if(vetor[i].cod == ide ){
                return i;
            }
        }
        return -1;
    }

    int remove_elemento(int posicao, No vetor[], int *posicao_atual){
        if(posicao<0 || posicao>=*posicao_atual){
            return 0;
        }
        
        vetor[posicao] = vetor[(*posicao_atual) - 1];
        (*posicao_atual)--;
        return 1;
    }

    void mostra(No vetor[], int posicao){
        for(int i= 0; i< posicao; i++){
            printf("Posição %d: Código = %d, Nome = %s\n" , i, vetor[i].cod, vetor[i].nome);
        }
    }

int main(){
    int pos = 0;
    No primeiro = {1, "Ana Maria"};
    No segundo = {2, "Carlos Gomes"};
    No terceiro = {3, "Sara Vieira"};
    No vetor[10];

    vetor[0] = primeiro;
    vetor[1] = segundo;
    pos = 2;

    incluir(terceiro, vetor, &pos);

    int ide = 2;
    int pos_encontrada = procura(ide, vetor, pos);
    if(pos_encontrada != -1){
        printf("\nElemento encontrado na posição %d.\n" , pos_encontrada);
    }else{
        printf("O elemento não existe.");
    }

    int remover_posicao = 1;
    int remocao = remove_elemento(remover_posicao, vetor , &pos);
    if(remocao == 1){
        printf("O elemento foi removido!");
    }else{
        printf("Posição não encontrada!");
    }

    printf("\nElementos no vetor:\n");
    mostra(vetor, pos);
   

    return 0;
}