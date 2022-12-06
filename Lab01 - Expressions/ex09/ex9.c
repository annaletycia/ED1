#include <stdio.h>
#include <math.h>

int main(){

  int x, y;
  float d;

  printf("<< Distancia >>\n");
  printf("Digite a coordenada x:");
  scanf("%d", &x);
  printf("Digite a coordenada y:");
  scanf("%d", &y);
  d = sqrt(x*x + y*y);
  printf("A distancia entre os pontos (%d,%d) e (0,0) eh %.1f", x,y,d);

  return 0;
  
}