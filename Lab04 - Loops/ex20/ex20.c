#include <stdio.h>

int main(){

    int num, a, b, valor = 1;
    
    printf("Triangulo de Floyd\n");
    printf("Digite o numero de linhas: \n");
    scanf("%d", &num);

      for(a=1; a<=num; a++){ //numero de linhas
        for(b=1; b<=a; b++){ //numero de valores por linha
            printf("%d ", valor);
            valor++;
        }
          printf("\n");      
      }
    return 0;
}