#include <stdio.h>

int main(){

  int num, soma=0,i;

  printf("<<Soma de n valores naturais>>\n");
  printf("Quantos numeros deseja somar? ");
  scanf("%d", &num);
  i = num;

  while(num>0){
    soma = soma + num;
    num--;
  }

  printf("A soma dos %d primeiros numeros naturais eh: %d", i, soma);

  return 0;
}