#include <stdio.h>

typedef struct ponto
{
    float x, y;
}ponto;

void imprime_ponto(ponto num){

    printf("(%.0f,%.0f)\n", num.x, num.y);
}

int main(){

    ponto p1;

    printf("Digite o valor de x: ");
    scanf("%f", &p1.x);
    printf("Digite o valor de y: ");
    scanf("%f", &p1.y);

    printf("O ponto digitado eh: ");
    imprime_ponto(p1);

    return 0;
}

/*
Observação: Para os próximos exercícios, crie uma struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Faça uma função chamada imprime_ponto, que recebe uma 
struct do tipo ponto e mostra na tela o ponto no seguinte formato 
(ponto.x, ponto.y)

Exemplo de chamada da função:
imprime_ponto(p)

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x: 10
Digite o valor de y: 5
O ponto digitado eh: (10,5)
-------------------------------------------------------------------------------
*/