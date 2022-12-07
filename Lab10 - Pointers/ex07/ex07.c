#include <stdio.h>
#include <string.h>

int main(){

    char nome[] = "Jose Augusto";
    char *p = nome;

    for(int i=0; i<strlen(nome);i++){
        printf("%c", *(p+i));
    }
    printf("\n");

    return 0;
}

/*
7) Utilizando aritmética de ponteiros, mostre na tela o conteúdo da string char nome[] = “José Augusto”. 
Utilize o   printf com %c e não %s
*/