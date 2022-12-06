#include <stdio.h>

int main(){

int n1, n2, n3, n4, m;

  printf("<<Media Aritmetica>>\n");
  printf("Digite a 1a nota:");
  scanf("%d", &n1);
  printf("Digite a 2a nota:");
  scanf("%d", &n2);
  printf("Digite a 3a nota:");
  scanf("%d", &n3);
  printf("Digite a 4a nota:");
  scanf("%d", &n4);

m = (n1+n2+n3+n4)/4;

printf("==NOTAS==\nNota 1: %d, Nota 2: %d, Nota 3: %d, Nota 4: %d\n", n1,n2,n3,n4);
printf("Media: %d\n", m);

  return 0;
}