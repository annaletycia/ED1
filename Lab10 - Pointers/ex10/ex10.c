#include <stdio.h>

    int main(){

        int vet[10];

        for(int i=0; i<10; i++){
            printf("Digite o %d numero: ", i+1);
            scanf("%d", vet+i);
           
        }
        for(int i=9; i>=0; i--){
            printf("%d ", vet[i]);
        }
 return 0;
}

/*
10) Imprima o conteúdo de um vetor de int de 10 posições da última posição até a primeira utilizando 
aritmética de ponteiros e SEM declarar variáveis do tipo ponteiro (ou seja, o nome do vetor terá que ser usado como o ponteiro)
*/