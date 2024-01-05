#include <iostream>
                        //Passo 1: inclusao de bibliotecas
using namespace std;



typedef struct aluno {
    int mat;
    string nome;            //Passo2: estrutura de dados chamada aluno
    aluno* prox;

}Aluno;


Aluno* no(int mat, string nome){
    Aluno* novo = new Aluno();  
    novo-> mat = mat;
    novo-> nome = nome;         //Passo 3: cria um novo aluno com matricula e nome e retorna um ponteiro para esse aluno
    novo-> prox = NULL;
    return novo;
}

Aluno* inicio = NULL;       //Passo 4: variaveis globais para manter o inicio e o fim da lista de alunos
Aluno* fim = NULL;

void incluirNoFinal(Aluno* n){
    if(fim == NULL){
        inicio = n;
        fim = n;              //Passo 5: Incluir Aluno no final da Lista;

    }else{
        fim-> prox = n;
        fim = n;

    }
}

void incluirNoInicio(Aluno* n){

    if(inicio == NULL){
        inicio = n;
        fim = n;            //Passo 6: Insere o aluno no inicio da lista;
    
    }else {
        n-> prox = inicio;
        inicio = n;
    }
}

Aluno* procura(int mat) {
    Aluno* atual = inicio;
    while(atual != NULL) {
        if(atual->mat == mat) {     //Passo 7: Encontrar aluno pela matricula fornecida
            return atual;
        }

        atual = atual-> prox;
    }
    return NULL;

}

void mostrarAlunos() {
    Aluno* atual = inicio;          //Percorre a lista de alunos
    while (atual != NULL) {
        cout << "Matrícula: " << atual->mat << ", Nome: " << atual->nome << endl;
        atual = atual -> prox;
    }
}
    
    
    int main(){
        Aluno* novo = no(1, "Maria"); //Testa as funções
        incluirNoFinal(novo);

        novo = no(2, "Sara");
        incluirNoInicio(novo);

        mostrarAlunos();

        return 0;
      
    }
    
    



