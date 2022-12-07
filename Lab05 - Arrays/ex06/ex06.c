#include <stdio.h>

int main(){

int i, maior,menor, vetor[5];
float media=0;
int pos_ma, pos_me;

    printf(">>5 valores com indice<<\n");
        for(i=0;i<5;i++){
            printf("Entre com o numero %d: ", i+1);
            scanf("%d", &vetor[i]);
            media = media + vetor[i];
        }

        printf("\nOs numeros digitados sao: ");

    maior=vetor[0];
    menor=vetor[0];

        for(i=0;i<5;i++){
            printf("%d ", vetor[i]);
            if(vetor[i]>maior){
                maior = vetor[i];
                pos_ma = i;
            }
            if(vetor[i]<menor){
                menor = vetor[i];
                pos_me = i;
            }
        }
        printf("\nO maior valor eh: %d, localizado na posicao %d do vetor\n", maior,pos_ma);
        printf("O menor valor eh: %d, localizado na posicao %d do vetor\n", menor,pos_me);
        printf("A media eh: %.1f\n", media/5);

        return 0;
}

/*
Fazer um programa para ler 5 valores, e, em seguida, mostrar todos os valores
lidos juntamente com o maior (Max), o menor (Min) e a média (Mean) dos valores
Mostrar o índice (index) do vetor associado ao maior número e ao menor número 

Exemplo de saída:
<< Five Values with index >>
Input #1: 5
Input #2: 6
Input #3: 4
Input #4: 0
Input #5: 3

The numbers entered are: 5 6 4 0 3
Max. Value: 6, index 1 of the array
Min. Value: 0, index 3 of the array
Mean: 3.6
*/