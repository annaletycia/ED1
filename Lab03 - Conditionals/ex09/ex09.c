#include <stdio.h>

int main(){

 float venda, comissao;

    printf("<<Comissao>>\n");
    printf("Digite o valor da venda: ");
    scanf("%f", &venda);

      if(venda>=100000){
        comissao = 0.16*venda;
        printf("A comissao será de R$%.2f\n", 700 + comissao);
      }
      else{
        comissao = 0.14 * venda;
          if(venda>=80000 && venda<100000){
            printf("A comissao sera de R$%.2f\n", 650+comissao);
          }
           if(venda>=60000 && venda<80000){
            printf("A comissao sera de R$%.2f\n", 600+comissao);
          }
           if(venda>=40000 && venda<40000){
            printf("A comissao sera de R$%.2f\n", 550+comissao);
          }
           if(venda>=20000 && venda<20000){
            printf("A comissao sera de R$%.2f\n", 500+comissao);
          }
           if(venda<20000){
            printf("A comissao sera de R$%.2f\n", 400+comissao);
          }
      }

 return 0;
}