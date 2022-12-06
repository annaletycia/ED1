#include <stdio.h>

int main(){

int d, vb, vl, ISS, IR;

printf("<< Pagamento Encanador >>\n");
printf("Digite o numero de dias trabalhados: ");
scanf("%d", &d);
vb = d*30;
printf("Valor bruto R$: %d\n", vb);

ISS = 0.04 * vb;
IR = 0.08 * vb;
vl = vb - ISS - IR;

printf("Valor liquido R$: %d\n", vl);
printf("ISS R$: %d\n", ISS);
printf("IR R$: %d\n", IR);

  return 0;
}
