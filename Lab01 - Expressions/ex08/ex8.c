#include <stdio.h>

int main(){

int d;
float vb, vl, ISS, IR;

printf("<< Pagamento Encanador >>\n");
printf("Digite o numero de dias trabalhados: ");
scanf("%d", &d);
vb = d*30;
printf("Valor bruto R$: %.0f\n", vb);

ISS = 0.04 * vb;
IR = 0.08 * (vb - ISS);
vl = vb - ISS - IR;

printf("Valor liquido R$: %.2f\n", vl);
printf("ISS R$: %.0f\n", ISS);
printf("IR R$: %.2f\n", IR);

  return 0;
}