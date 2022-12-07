#include <stdio.h>

int main(){

 float produto, imposto;
 int unidade;

 printf("<<Valor do Produto com Imposto>>\n");
 printf("Digite o valor do produto R$:");
 scanf("%f", &produto);
 printf("Digite a unidade da federacao:");
 scanf("%d", &unidade);

    if(unidade == 1){
      imposto = produto + (0.07 * produto);
      printf("Valor final com impostos R$:%.2f\n", imposto);
    }

    else if(unidade == 2){
       imposto = produto + (0.12 * produto);
       printf("Valor final com impostos R$:%.2f\n", imposto);
    }

    else if(unidade == 3){
       imposto = produto + (0.15 * produto);
       printf("Valor final com impostos R$:%.2f\n", imposto);
    }

    else if(unidade == 4){
       imposto = produto + (0.08 * produto);
       printf("Valor final com impostos R$:%.2f\n", imposto);
    }
    else{
      printf("ERRO\n");
    }

 return 0;
}