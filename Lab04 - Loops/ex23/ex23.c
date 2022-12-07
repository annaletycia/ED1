#include <stdio.h>

int main(){

  int n,i;
  float fat=1, soma = 0;

  printf("<<Numero Neperiano>>\n");
  printf("Entre com o numero de termos: ");
  scanf("%d", &n);
  
    for(i=1;i<n;i++){

      fat = fat * i;
      soma = 1/fat + soma;

    }

    printf("e ~ %f\n", soma+1);

return 0;
}