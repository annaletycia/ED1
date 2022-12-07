#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char nome1[50], nome2[50];
    int aux;

    printf("<<Compara nomes>>\n");
    printf("Digite o nome 1: ");
    gets(nome1);
    printf("Digite o nome 2: ");
    gets(nome2);

    aux = strcmp(nome1,nome2);

    if(aux == 0){
        printf("\nOs nomes digitados sao iguais\n");
    }
    else{
        printf("\nOs nomes digitados sao diferentes\n");
    }
    return 0;
}