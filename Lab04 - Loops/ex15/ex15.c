#include <stdio.h>
#include <math.h>

int main(){

  int bits,i,bit,dec=0, soma=0;

    printf("<<Conversor binario-decimal>>\n");
    printf("Entre com o numero de bits: ");
      scanf("%d", &bits);
      int aux = bits - 1;

      for(i=1;i<=bits;i++){
        printf("Digite o bit #%d: ", i);
        scanf("%d", &bit);
        soma = bit * pow(10,(bits-i)) + soma;
        dec = (bit * pow(2,aux)) + dec;
        aux--;
      }

    printf("O numero binario %d em decimal eh %d\n", soma,dec);

return 0;
}