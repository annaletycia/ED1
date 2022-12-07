//1
#include <stdio.h>

int main(){

    printf("<< Pointers >>\n");
    int val[5] = {2,4,5,8,10};
    unsigned int posicao;
    posicao = &val[2]; //fake pointer

    printf("val[5]=");
   for(int i=0; i<5;i++){
       printf("%d ", val[i]);
   }
   printf("\nNovo valor de val[2]: ");
   scanf("%u", posicao);
   printf("\nNovo val[5]=");
   for(int i=0;i<5;i++){
        printf("%d ", val[i]);
    }

return 0;
}

/*
Crie um programa que contenha a seguinte variável
int val[5] = {2,4,5,8,10};
                  ^
Utilizando a função scanf, altere o valor de 5 para 6. 
Não use o operador & no scanf. Utilize uma variável do tipo inteira*
para guardar o endereço da posição do vetor.

*obs:
unsigned int (para programas em 32bit)
unsigned long int (para programas em 64)

*/