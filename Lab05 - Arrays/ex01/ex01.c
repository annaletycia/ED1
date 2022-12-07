#include <stdio.h>

int main(){

int vetor[6];

    printf(">>Listando um vetor<<\n");
    printf("Entre com o numero 1: ");
    scanf("%d", &vetor[0]);
    printf("Entre com o numero 2: ");
    scanf("%d", &vetor[1]);
     printf("Entre com o numero 3: ");
    scanf("%d", &vetor[2]);
    printf("Entre com o numero 4: ");
    scanf("%d", &vetor[3]);
    printf("Entre com o numero 5: ");
    scanf("%d", &vetor[4]);
    printf("Entre com o numero 6: ");
    scanf("%d", &vetor[5]);

    printf("\nOs valores lidos sao: %d %d %d %d %d %d\n", vetor[0],vetor[1],vetor[2],vetor[3],vetor[4],vetor[5]);

return 0;
}

/*
Crie um programa que lê 6 valores inteiros e em seguida mostra na tela os 
valores lidos. Não utilize loops e utilize vetores para armazenar os números.
nova linha para testar!
 
Exemplo de saída:
<< Listando um vetor >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 0
Entre com o numero 5: 3
Entre com o numero 6: 6

Valores lidos: 5 6 4 0 3 6
*/
