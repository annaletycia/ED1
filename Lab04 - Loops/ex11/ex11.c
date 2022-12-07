#include <stdio.h>

int main(){

  int num, soma=0,i;

  printf("<<Soma de n valores naturais>>\n");
  printf("Quantos numeros deseja somar? ");
  scanf("%d", &num);
  i = num;

  do{
    soma = soma + num;
    num--;
  }while(num>0);

  printf("A soma dos %d primeiros numeros naturais eh: %d", i, soma);

  return 0;
}