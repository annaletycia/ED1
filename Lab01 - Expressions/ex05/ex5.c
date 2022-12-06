#include <stdio.h>

int main(){

float s, a;

printf("<<Aumento Salarial>>\n");
printf("Digite o valor do salario: R$");
scanf("%f", &s);
a = (0.25 * s) + s;
printf("Apos 25%% de aumento, o salario fica em R$%.2f\n", a);

  return 0;
}