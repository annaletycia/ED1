#include <stdio.h>

int main(){

    int num[5], par[5], impar[5];
    int i, k=0, j=0;
 
    printf("<<Pares e Impares>>\n");

        for(i=0;i<5;i++){
            
            printf("Digite o valor %d: ",i+1);
            scanf(" %d", &num[i]);

            if(num[i] % 2 != 0){
                impar[k] = num[i];               
                k++;
            
            }else{
                par[j] = num[i];               
                j++;
            }
        }

        printf("\nImpares: ");
        for(i=0;i<k;i++){
              if(i==0){
                printf("%d", impar[i]);
              }else{
                printf(", %d", impar[0]);                
              }
        }

        printf("\nPares: ");
        for(i=0;i<j;i++){
            if(i==0){
              printf("%d", par[0]);
            }else{      
            printf(", %d", par[i]);
            }
        }
    return 0;

}

/*
Leia 5 números inteiros e armazene em um vetor v. Crie dois novos vetores v1 e v2. Copie os valores ímpares de v para v1, e os valores pares de v para v2. Note que cada um dos vetores v1 e v2 tem no máximo 5 elementos, mas nem todos os elementos são utilizados. No final escreva os elementos UTILIZADOS de v1 e v2.  
Exemplo de saída:
<< Pares e Ímpares >>
Digite o valor 1: 51
Digite o valor 2: 60
Digite o valor 3: 70
Digite o valor 4: 80
Digite o valor 5: 60

Ímpares: 51
Pares: 60, 70, 80, 60
*/