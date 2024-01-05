#include <stdio.h>
#include <stdlib.h>

int main(){
    
    float numero_alunos;

    printf("Digite a quantidade de alunos na turma: ");
    scanf("%f",&numero_alunos);

    if(numero_alunos<=0){
        printf("O número de alunos deve ser maior que zero");
        return 1;

    }

    float *notas = (float *)malloc((size_t) numero_alunos * sizeof(float));

    if (notas == NULL) {
        printf("ERRO!");
        return 1;
    }

    for(int i = 0; i < numero_alunos; i++){
        printf("Digite a nota do aluno %d: " , i + 1);
        scanf("%f", &notas[i]);
    }

    float soma = 0.0;
    for(int i = 0; i < numero_alunos; i++){
        soma += notas[i];
    }

    float media = soma/numero_alunos;

    printf("A média das notas é: %.2f\n" , media);

    free(notas);


    
    return 0;
}