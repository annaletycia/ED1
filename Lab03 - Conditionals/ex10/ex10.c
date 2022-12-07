#include <stdio.h>
#include <stdbool.h>

int main(){

  int A, B;
  bool bA = 1, bB = 1;

  printf("==Operadores Booleanos==\n");
  printf("Digite 0 para falso e nao 0 para verdadeiro\n");

  printf("Entre com o primeiro valor (A):");
  scanf("%d", &A);
    if(A==0){
      bA = 0;
    }

  printf("Entre com o segundo valor (B):");
  scanf("%d", &B);
      if(B==0){
      bB = 0;
      }

        if(bA&&bB==1){
          printf("A and B: VERDADEIRO\n");
        }
        else{
          printf("A and B: FALSO\n");
        }
        if(bA||bB == 1){
          printf("A or B: VERDADEIRO\n");
        }
        else{
          printf("A or B: FALSO\n");
        }
        if(bA==bB){
          printf("A xor B: FALSO\n");
        }
        else{
          printf("A xor B: VERDADEIRO\n");
        }
        if(!bA == 0){
          printf("not A: FALSO\n");
        }
        else{
          printf("not A: VERDADEIRO\n");
        }
        
  return 0;
}