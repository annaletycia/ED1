#include <stdio.h>

int main(){

        printf("<<Poupanca>>\n");
        printf("Jose possui no banco R$50.000,00 e Carlos R$25.000,00.\nCarlos poupa R$ 3.000,00 por mes, enquanto Jose poupa R$800,00.\n");
            float capC = 50000; float poupC = 800;
            float capJ = 25000; float poupJ = 3000;
            float tempo = (capC - capJ)/(poupJ - poupC)+1;
        printf("Logo, Carlos ficara com mais dinheiro que Jose em %.0f ano(s).\n", tempo/12);

return 0;
}