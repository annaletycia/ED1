#include <stdio.h>
#include <math.h>

int main(){

  int i;
  double x, pot;
	
  printf("<<Quantidade maxima>>\n");
  for(i=2; i<=128; i=i*2){
    pot = pow(2,i);
      if(i<=4){
        printf("Com %d bits eh possivel enderecar %.0f posicoes de memoria\n", i, pot);
  }
      else{
         printf("Com %d bits eh possivel enderecar %.14g posicoes de memoria\n", i, pot);
    }
  }
  return 0;
}