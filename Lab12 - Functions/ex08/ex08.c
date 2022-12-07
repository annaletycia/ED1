#include <stdio.h>

float incp(float y, float num){

    float aux;
    if(num>0){
        aux = (num * y) + y;
    }else{
        aux = (num * y) + y;
    }
    return aux;
}

int main(){

    float y, x;

    printf("Digite o valor de y: ");
    scanf("%f", &y);
    printf("Digite o percentual de alteracao x: ");
    scanf("%f", &x);
    float w = incp(y,x);
    printf("O valor alterado eh: %f\n", w);

    printf("\nDigite o valor de y: ");
    scanf("%f", &y);
    printf("Digite o percentual de alteracao x: ");
    scanf("%f", &x);
    float z = incp(y,x);
    printf("O valor alterado eh: %f\n", z); 
 

    return 0;
}

/*
=> Faça uma função que altere um valor de um número real em x%. Se 
o valor de x for negativo ele deve ser decrementado, se for positivo 
aumente.

Uso da função: 
x = incp(y,10);
z = incp(y,-20);

-------------------------------------------------------------------------------
Exemplo de Saída 1:

Digite o valor de y: 100
Digite o percentual de alteracao: 0.10 // 0.10 equivale a 10%
O valor alterado eh: 110
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Exemplo de Saída 2:

Digite o valor de y: -100
Digite o percentual de alteração: .10
O valor alterado eh: -110
-------------------------------------------------------------------------------
*/