#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    char string[50], string1[50], inverso[50];
    int j=0;
    
    printf("<<Palindromo>>\n\n");
    printf("Digite a string: ");
    gets(string);

    for(int k=0; k<strlen(string);k++){
    string1[k] = toupper(string[k]);
    }

    for(int i=(strlen(string1))-1; i>=0;i--){
        inverso[j] = string1[i];
        j++;
    }
   int aux = strcmp(inverso,string1);

    if(aux == 0){
        printf("%s eh palindromo!\n", string);
    }else{
        printf("%s nao eh palindromo\n", string);
    }
    return 0;
}