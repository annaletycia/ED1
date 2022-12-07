#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char nome[50], first[50],last[50];
    int i=0;

    printf("<<Vetor de Char>>\n\n");
    printf("Digite um nome e sobrenome: ");
    gets(nome);

    printf("Nome: ");
    while(nome[i] != ' '){
        first[i] = nome[i];
        printf("%c", first[i]);
        i++;
    }
    printf("\n");
    printf("Sobrenome: ");
    i++;
    while(nome[i] != '\0'){
        last[i] = nome[i];
        printf("%c", last[i]);
        i++;
    }

    return 0;
}