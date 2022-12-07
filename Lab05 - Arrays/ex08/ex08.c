#include <stdio.h>
#include <math.h>

int main(){

int i, vetor[5], cont=0,media;
double aux = 0, DP;

    printf(">>Media e desvio-padrao<<\n");
        for(i=0;i<5;i++){
            printf("Digite o valor %d: ", i+1);
            scanf("%d", &vetor[i]);
            cont = cont + vetor[i];
        }
    media = cont/5;

        for(i=0;i<5;i++){
            aux = aux + pow(vetor[i]-media,2);
        }
    DP = sqrt(aux/4);

    printf("\nA media eh %d e o desvio padrao eh %.2f\n", media,DP);
    
    return 0;
}

/*
Calcular a média e o desvio padrão amostral de 5 números informados pelo usuário.
obs: desvio-padrão (amostral, normalizado por N-1)

Exemplo de saída:
<< Media e desvio-padrao >>
Digite o valor 1: 50
Digite o valor 2: 60
Digite o valor 3: 70
Digite o valor 4: 80
Digite o valor 5: 60
A media eh 64 e o desvio-padrao eh 11.40
*/
