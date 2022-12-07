#include <stdio.h>
#include <math.h>

int main(){

 float num, sqrtnum;

    printf("<<Quadrado Perfeito>>\n");
    printf("Digite um numero:");
    scanf("%f", &num);
 
      if(pow(sqrt(num),2) == num){
        sqrtnum = sqrt(num);
          if(fmod(num,sqrtnum) == 0){
         printf("%.0f eh um quadrado perfeito!\n", num);
         printf("Sua raiz quadrada eh %.0f\n", sqrt(num));
        }
          else{
         printf("%.0f nao eh um quadrado perfeito!\n", num);
      }
      }
      else{
       printf("%.0f nao eh um quadrado perfeito!\n", num);
      }

 return 0;
}