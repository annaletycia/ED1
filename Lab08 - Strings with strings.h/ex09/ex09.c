#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char string[50];

    printf("<<Invertendo>>\n\n");
    printf("Digite a string: ");
    gets(string);

    printf("Saida invertida: ");
    for(int i=strlen(string); i>=0;i--){
        printf("%c", string[i]);
    }
    printf("\n");

    return 0;
}