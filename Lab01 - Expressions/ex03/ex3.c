#include <stdio.h>

int main(){

  int x;

  printf("<<Sucessor e Antecessor>>\n");
  printf("Digite um numero:");
  scanf("%d", &x);
  printf("O antecessor do numero %d eh %d e seu sucessor eh %d\n", x, x-1, x+1);

  return 0;
}