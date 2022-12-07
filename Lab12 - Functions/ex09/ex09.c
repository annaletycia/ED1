#include <stdio.h>

void incp(float y, float num, float *p){

    if(num>0){
        *p = (num * y) + y;
    }else{
        *p = (num * y) + y;
    }
}

int main(){

    float y, x;

    printf("Digite o valor de y: ");
    scanf("%f", &y);
    printf("Digite o percentual de alteracao x: ");
    scanf("%f", &x);
    float w;
    incp(y,x, &w);
    printf("O valor alterado eh: %f\n", w);

    printf("\nDigite o valor de y: ");
    scanf("%f", &y);
    printf("Digite o percentual de alteracao x: ");
    scanf("%f", &x);
    float z;
    incp(y,x, &z);
    printf("O valor alterado eh: %f\n", z); 
 

    return 0;
}

/*
=> Faça uma função que altere um valor de um número real em x%. 
Se o valor de x for negativo ele deve ser decrementado, se for
positivo aumente. O valor da variável deve ser passada por parâmetro,
ou seja, o retorno deve  ser void.


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