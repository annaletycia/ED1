#include <stdio.h>

int main(){

  int n, i, j, k=0, c=0;

  printf("<<Multiplos>>\n");
  printf("Entre com o valor de n: ");
  scanf("%d", &n);
  printf("Entre com o valor de i: ");
  scanf("%d", &i);
  printf("Entre com o valor de j: ");
  scanf("%d", &j);
  
  printf("Os %d primeiros numeros multiplos de i ou j sao: ", n);

    while(c<n){
      
        if(k == 0){
          printf("%d", k);
          c++;
          k++;
        }

        if(k%i==0 || k%j==0){
          printf(",%d", k);
          c++;
        }
        k++;
        
    }

return 0;
}