#include <stdio.h>
#include <math.h>

int main(){

 float A,B,C;

 printf("<<Raizes de uma Equaçao 2o Grau>>\n");
 printf("Entre com o valor do coeficiente A: ");
 scanf("%f", &A);
 if(A==0){
   printf("ERRO! 'A' precisa ser diferente de 0!\n");
 }
 else{
 printf("Entre com o valor do coeficiente B: ");
 scanf("%f", &B);
 printf("Entre com o valor do coeficiente C: ");
 scanf("%f", &C);

 float delta = (pow(B,2)-4*A*C);
 float sqrtdelta = sqrt(delta);
 float raizP = ((-B + sqrtdelta)/(2*A));
 float raizN = ((-B - sqrtdelta)/(2*A));

  if(delta == 0){
    printf("A equaçao apresenta uma unica raiz real: %.1f\n", raizP);
  }
  if(delta>0){
    printf("Raiz real 1: %.1f\n", raizP);
    printf("Raiz real 2: %.1f\n", raizN);
  }
  if(delta<0){
    delta = -delta;
    sqrtdelta = sqrt(delta);
    printf("Raiz complexa 1: %.2f + %.2f*i\n", (-B)/(2*A), (sqrtdelta)/(2*A));
    printf("Raiz complexa 2: %.2f - %.2f*i\n", (-B)/(2*A), (sqrtdelta)/(2*A));
  }

 return 0;
}
}