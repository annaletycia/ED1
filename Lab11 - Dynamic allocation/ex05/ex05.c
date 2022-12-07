#include <stdio.h>
#include <stdlib.h>
//lembre-se de incluir as bibliotecas adequadas

typedef struct coordenadas{
        int x, y;
    }Coordenadas;

int main(){

    int n, i;
    Coordenadas *p;
    int *direita[2], esquerda[2], acima[2], abaixo[2];

    printf("<< Vetor de pontos alocados dinamicamente >>\n");

    printf("Quantos pontos deseja digitar: ");
    scanf("%d", &n);

    p = (Coordenadas *)malloc(n*sizeof(Coordenadas));
    if(p==NULL){
        printf("Memoria insuficiente");
        system("pause");
    }

    for(i=0;i<n;i++){
        printf("\nEntre com a coordenada x do ponto %d: ", i+1);
        scanf("%d", &p[i].x);
        printf("Entre com a coordenada y do ponto %d: ", i+1);
        scanf("%d", &p[i].y);
    }
    
    printf("\nOs pontos digitados sao: ");
    for(i=0;i<n;i++){
        printf("(%d,%d); ", p[i].x,p[i].y);
    }
    printf("\n\n");

direita[0] = p[0].x;
direita[1] = p[0].y;

esquerda[0] = p[0].x;
esquerda[1] = p[0].y;

abaixo[0] = p[0].x;
abaixo[1] = p[0].y;

acima[0] = p[0].x;
acima[1] = p[0].y;

    for(i=1;i<n;i++){
        if(p[i].x < esquerda[0]){
            esquerda[0] = p[i].x;
            esquerda[1] = p[i].y;
        }
    }    
        printf("Ponto mais a esquerda: (%d,%d)\n", esquerda[0], esquerda[1]);
    
    for(i=1;i<n;i++){
        if(p[i].x > direita[0]){
            direita[0] = p[i].x;
            direita[1] = p[i].y;
        }
    }   
        printf("Ponto mais a direita: (%d,%d)\n", direita[0], direita[1]);
    
    for(i=1;i<n;i++){
        if(p[i].y > acima[1]){
            acima[1] = p[i].y;
            acima[0] = p[i].x;
        }
    }
        printf("Ponto mais acima: (%d,%d)\n", acima[0],acima[1]);
    
    for(i=1;i<n;i++){
        if(p[i].y < abaixo[1]){
            abaixo[1] = p[i].y;
            abaixo[0] = p[i].x;
        }
     }
        printf("Ponto mais abaixo: (%d,%d)\n", abaixo[0],abaixo[1]);
    

    free(p);

    return 0;
}

/*
5) Modifique o programa anterior incluindo quatro ponteiros, que apontarão para
os seguintes pontos: mais a esquerda, mais a direita, mais acima, mais abaixo.
Mostre quem são esses pontos utilizando esses ponteiros.

Exemplo de saída:
<< Vetor de pontos alocados dinamicamente >>
Digite a quantidade de pontos a serem armazenados: 5

Digite o valor da coordenada x do ponto 1: 2
Digite o valor da coordenada y do ponto 1: 5

Digite o valor da coordenada x do ponto 2: 4
Digite o valor da coordenada y do ponto 2: 8

Digite o valor da coordenada x do ponto 3: 3
Digite o valor da coordenada y do ponto 3: 4

Digite o valor da coordenada x do ponto 4: 6
Digite o valor da coordenada y do ponto 4: 7

Digite o valor da coordenada x do ponto 5: 23
Digite o valor da coordenada y do ponto 5: 25


Os pontos digitados sao: (2,5); (4,8); (3,4); (6,7); (23,25)

Ponto mais a esquerda: (2,5)
Ponto mais a direita: (23,25)
Ponto mais acima: (23,25)
Ponto mais abaixo: (3,4)

*/