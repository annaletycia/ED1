#include <stdio.h>
#include <math.h>

int main(){

  int bit1, bit2, bit3, bit4, decimal;

  printf("<<Conversor de numeros binarios>>\n");
  printf("Digite o 1o. bit: ");
  scanf("%d", &bit1);
  printf("Digite o 2o. bit: ");
  scanf("%d", &bit2);
  printf("Digite o 3o. bit: ");
  scanf("%d", &bit3);
  printf("Digite o 4o. bit: ");
  scanf("%d", &bit4);

  int a = bit1 * pow(2,3);
  int b = bit2 * pow(2,2);
  int c = bit3 * pow(2,1);
  int d = bit4 * pow(2,0);
  decimal = a + b + c + d;

  printf("O nUmero binario %d%d%d%d corresponde ao numero decimal %d\n", bit1, bit2, bit3, bit4, decimal);

  return 0;
}

/*
=> Faça um conversor de número binário para decimal (inteiro). 
O número deve ter 4 bits, sendo o bit mais significativo digitado primeiro. 
Mostrar na resposta o número binário e o número decimal.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Conversor de numeros binarios >>
Digite o 1o. bit: 1
Digite o 2o. bit: 0
Digite o 3o. bit: 1
Digite o 4o. bit: 1
O numero binario 1011 corresponde ao numero decimal 11
-------------------------------------------------------------------------------
*/