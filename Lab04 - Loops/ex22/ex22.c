/* Se for calculado o fatorial do 10! ate o 15! com o mesmo modelo do exercicio anterior, como ilustrado abaixo, o resultado ficara errado, pois a expressao nao vai considerar os numeros antes do 10 no momento de realizar o fatorial e portanto ira gerar um erro.

#include <stdio.h>

int main(){

    int fat=1;

    printf("<<Fatorial>>\n");

    for(int i=10;i<16;i++){
            fat = fat * i;
                printf("%d! = %d\n", i,fat);
    }
return 0;
}

Para resolver esse problema é preciso alterar a variavel fat para float e realizar a conta incluindo todos os valores de 1 ate 15, mas imprimindo somente aqueles que sao maiores ou iguais a dez:
*/

#include <stdio.h>

int main(){

float fat = 1;

  printf("<<Fatorial>>\n");

    for(int i=1;i<16;i++){
            fat = fat * i;
              if(i>=10){
                printf("%d! = %.0f\n", i,fat);
    }
    }

return 0;
}