#include <stdio.h>
#include <stdlib.h>
    
    float soma(float a , float b){
        return a + b;
    }
    float subtracao(float a, float b){
        return a - b;
    }
    float multiplicacao(float a, float b){
        return a * b;
    }
    float divisao(float a, float b){
        if(b != 0){
            return a / b;
        }else{
            printf("Error.\n");
        return 0.0;
    }
}

    int main(){
        char opcao;
        float a, b , resultado;
        int continuar= 1;

        while(continuar){
            printf("Escolha um operador: (+ , - , x , /) ou 'q' para sair:\n ");
            scanf(" %c", &opcao);

            if(opcao == 'q' || opcao == 'Q'){
                continuar = 0;
                continue;
            }

            if(opcao != '+' && opcao != '-' && opcao != '*' && opcao != '/'){
                printf("Operador inválido.\n");
                continue;
            }
            

        printf("Informe o primeiro número:");
        scanf(" %f", &a);
        printf("Informe o segundo número:");
        scanf(" %f", &b);
        

        switch (opcao){
            case '+':
                resultado = soma(a, b);
                break;
            case '-':
                resultado = subtracao(a, b);
                break;
            case '*':
                resultado = multiplicacao(a, b);
                break;
            case '/':
                resultado = divisao(a, b);
                break;
            default:
                printf("Opção inválida\n");
                continue;
        }

        printf("O resultado é: %.2f\n", resultado);
    }
        printf("Programa encerrado!\n");
        
        return 0;
    }

    
