#include <stdio.h>
#include <stdlib.h>
//lembre-se de incluir as bibliotecas adequadas

int main(){
    printf("<< Par ou Impar >>\n");

int *p, num, i;

    printf("Quantos numeros serao lidos: ");
    scanf("%d", &num);

    p = (int *)malloc(num*sizeof(int));

    for(i=0;i<num;i++){
        printf("Digite o numero (%d): ", i+1);
        scanf("%d", &p[i]);
    }

    int impar=0;
    int par=0;

    for(i=0;i<num;i++){
        if(p[i]%2 != 0){
            impar++;
        }
    }printf("%d numeros impares dos %d inteiros lidos\n", impar, num);
    
    for(i=0;i<num;i++){
        if(p[i]%2==0){
            par++;
        }
    }printf("%d numeros pares dos %d inteiros lidos\n",par, num);
    
    free(p);

    return 0;
}

/*
3) Faça um programa que leia n inteiros (definidos pelo usuário) 
armazenando-os em uma memória alocada dinamicamente. Em seguida, mostre
quantos dos n números são pares e quantos são ímpares.


Exemplo de saída:
<< Par ou Impar >>
Quantos inteiros serao lidos: 5
1º inteiro: 1
2º inteiro: 2
3º inteiro: 3
4º inteiro: 4
5º inteiro: 5

Sao pares: 2 dos 5 inteiros lidos.
Sao impares: 3 dos 5 inteiros lidos.

*/