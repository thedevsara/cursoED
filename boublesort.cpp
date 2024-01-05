#include <stdio.h>
#include <stdlib.h>

void bolha (int n,int* v) {
    int j = 0;
    int trocou = 0;
    for (j; j < n-1; j++)
    {
        for(int i = 0; i < n-i; i++){
            if (v[i] > v[i+1]){
                int t = v[i];
                v[i] = v[i+1];
                v[j+1] = t;
                trocou++;
            }
        }
    }
    
	 
	 
}

int PesquisaBinaria(int n, int *v, int procurado){
	int inicio = 0;
    int fim = n -1;
    while(inicio <= fim){
        int meio = (inicio + fim) /2;
        if(procurado < v[meio]){
            fim = meio - 1;
        }else if (procurado > v[meio]){
            inicio = meio + 1;
        }else{
            return meio;
        }
    }

    return -1;
	
	
}
	 
int main(){
	int v[4];
	for(int i=0;i<=3;i=i+1){
		printf("Digite o valor %d :",i);
		scanf("%d",&v[i]);
	}
    
    bolha(4, v);

    for (int i = 0; i < 4; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    int pesq_bin = PesquisaBinaria(4, v, 3);
    printf("%d", pesq_bin);
    
	//ordene o vetor V usando o m�todo da bolha	
    //mostre o vetor ordenado
    //pesquise no vetor usando o metodo de pesquisa binaria
		
}
