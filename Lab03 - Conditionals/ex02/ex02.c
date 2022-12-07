#include <stdio.h>

int main(){

 float temp, f, c;
 char unidade;

 printf("<<Conversor de Temperatura>>\n");
 printf("Digite a temperatura:");
 scanf("%f", &temp);
 printf("Digite a unidade:");
 setbuf(stdin, NULL);
 scanf("%c", &unidade);

    if(unidade == 'c'){
      c = temp;
      f = c * (9.0/5.0) + 32.0;
      printf("%.0f graus Celsius correspondem a %.0f graus Fahrenheit\n", c,f); 
    }

    else if(unidade == 'f'){
      f = temp;
      c = (5 * (f-32))/9;
      printf("%.0f graus Fahrenheit correspondem a %.0f graus Celsius\n", f,c); 
    }
    else{
      printf("ERRO");
    }
 return 0;
}