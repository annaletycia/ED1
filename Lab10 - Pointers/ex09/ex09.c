#include <stdio.h>

    int main(){

        double vet[10];

        for(int i=0; i<10; i++){
            printf("Digite o %d numero: ", i+1);
            scanf("%lf", vet+i);
           
        }
        for(int i=0; i<10; i++){
            printf("%lf ", vet[i]);
        }
 return 0;
 }

 /*
 9) Imprima o conteúdo de um vetor de double de 10 posições utilizando aritmética de ponteiros e 
 SEM declarar variáveis do tipo ponteiro (ou seja, o nome do vetor terá que ser usado como o ponteiro)
 */