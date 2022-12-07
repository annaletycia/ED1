#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char string[50], string1[50], consoantes[50];
    int i = 0;

    printf("<<Sem vogais>>\n");
    printf("Digite a string: ");
    gets(string);
    printf("Saida sem vogais: ");
    while(i<strlen(string)){
        string1[i] = toupper(string[i]);
        if(string1[i]=='A'||string1[i]=='E'||string1[i]=='I'||string1[i]=='O'||string1[i]=='U'){
            i++;
        }else{
            printf("%c",string[i]);
            i++;
        }
    }
    printf("\n");

    return 0;
}