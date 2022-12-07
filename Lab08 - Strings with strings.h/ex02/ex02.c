#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char nome[50];

printf("<<Vetor de Char>>\n");
printf("\nDigite um nome: ");
gets(nome);

printf("\nO nome digitado eh: ");

for(int i=0; i<strlen(nome);i++){
    printf("%c", toupper(nome[i]));
}
printf("\n");

return 0;
}