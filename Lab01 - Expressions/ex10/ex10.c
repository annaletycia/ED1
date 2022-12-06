#include <stdio.h>

int main(){

  float j1, j2, j3, premio, p1,p2,p3;

  printf("<<Loteria>>\n");
  printf("Bolao jogador1 R$: ");
  scanf("%f", &j1);
  printf("Bolao jogador2 R$: ");
  scanf("%f", &j2);
  printf("Bolao jogador3 R$: ");
  scanf("%f", &j3);

  printf("Informe o valor do premio: ");
  scanf("%f", &premio);

  p1 = (j1/(j1+j2+j3)) * premio;  
  printf("Jogador 1 recebera R$%.2f\n", p1);
  p2 = (j2/(j1+j2+j3)) * premio;  
  printf("Jogador 2 recebera R$%.2f\n", p2);
  p3 = (j3/(j1+j2+j3)) * premio;  
  printf("Jogador 3 recebera R$%.2f\n", p3);

  return 0;
}