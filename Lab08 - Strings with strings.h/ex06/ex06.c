#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char nome[50];
    int i=0;

    printf("<<Separa letras>>\n");
    printf("Digite o nome: ");
    gets(nome);

    while(i<strlen(nome)){
        printf("%da Letra: %c\n", i+1, nome[i]);
        i++;
    }
    return 0;
}