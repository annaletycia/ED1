#include <stdio.h>

int main(){

    char nome[40], first[40],last[40];
    int i=0, aux=0;

    printf("<<Nomes>>\n\n");
    printf("Digite o primeiro e ultimo nome: ");
    gets(nome);

    while(nome[i] != ' '){
        first[i] = nome[i];
        i++;
    }
    i++;
    printf("Nome: %s\n", first);

    while(nome[i] != '\0'){
        last[aux] = nome[i];
        aux++;
        i++;
    }
    printf("Sobrenome: %s", last);

    return 0;
}
/*
Faça um programa que recebe o nome e sobrenome de uma pessoa (máximo 40 caracteres), 
copie o nome para um vetor e o sobrenome para outro. Mostre os dois vetores copiados.

Exemplo de saída:
<< Nomes >>
Digite o primeiro nome e último nome: Carlos Silva
Nome: Carlos
Sobrenome: Silva
*/