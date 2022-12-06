#include <stdio.h>

int main(){

int premio=780000, p,s,t;

printf("<< Loteria >>\n");
printf("Valor total do premio: %d\n", premio);

p = (0.46 * premio);
s = (0.32 * premio);
t = premio - p - s;

printf("Primeiro vencedor: %d\n", p);
printf("Segundo vencedor: %d\n", s);
printf("Terceiro vencedor: %d\n", t);

  return 0;
}