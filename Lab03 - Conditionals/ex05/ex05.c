#include <stdio.h>

int main(){

 float IMC, peso, altura;

  printf("<<Calculo do IMC>>\n");
  printf("Digite seu peso:");
  scanf("%f", &peso);
  printf("Digite sua altura: ");
  scanf("%f", &altura);

  IMC = peso/(altura*altura);

    if(IMC<18.5){
      printf("Magreza\n");
    } 
    if(IMC>=18.5 && IMC<=24.9){
      printf("Saudavel\n");
    }
    if(IMC>=25.0 && IMC<=29.9){
      printf("Sobrepeso\n");
    }
    if(IMC>=30.0 && IMC<=34.9){
      printf("Obesidade grau 1\n");
    }
    if(IMC>=35.0 && IMC<=39.9){
      printf("Obesidade grau 2(severa)\n");
    }
    if(IMC>40.0){
      printf("Obesidade grau 3(morbida)\n");
    }

 return 0;
}