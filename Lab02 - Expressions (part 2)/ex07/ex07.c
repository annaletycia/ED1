#include <stdio.h>
#include <stdbool.h>

int main(){

  int A, B;
  bool bA = true, bB = true;

  printf("==Operadores Booleanos==\n");
  printf("Digite 0 para falso e nao 0 para verdadeiro\n");

  printf("Entre com o primeiro valor (A):");
  scanf("%d", &A);
    if(A==0){
      bA = false;
    }

  printf("Entre com o segundo valor (B):");
  scanf("%d", &B);
      if(B==0){
      bB = false;
      }

printf("A and B: %d\n", A&&B);
printf("A or B: %d\n", A||B);
printf("A xor B: %d\n", (A||B)&&!(A&&B));
printf("not A: %d\n", !A);

  return 0;
}

/*
=> Faça um algoritmo que mostre o funcionamento dos operadores lógicos. Peça para o usuário entrar com dois valores inteiros,, 
onde 0 implica em FALSO e qualquer outro número implica em VERDADEIRO.
Obs: XOR = (p || q) && !(p && q)

-------------------------------------------------------------------------------
Exemplo de saída:

== Operadores Booleanos ==
Digite 0 para falso e nao 0 para verdadeiro
Entre com o primeiro valor (A): -1
Entre com o segundo valor (B): 3
A and B: 1
A or B: 1
A xor B: 0
not A: 0
-------------------------------------------------------------------------------
*/