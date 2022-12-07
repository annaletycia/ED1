#include <stdio.h>

int main(){

  int num,i,aux=0;

    printf("<<Numeros primos>>\n");
    printf("Digite um numero: ");
      scanf("%d", &num);
    
      for(i=2;i<=num/2;i++){
        if(num % i == 0){
          aux++;
          break;
        }
    }
    if(aux == 0){
      if(num == 0 || num == 1){
        printf("O numero %d nao eh primo\n", num);
      }else{
      printf("O numero %d eh primo\n", num);
    }
    }else{
      printf("O numero %d nao eh primo\n", num);
    }

return 0;
}