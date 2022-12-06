#include <stdio.h>

int main()
{
 float c, f;
 printf("<<Conversor de Temperatura>>\n");
 printf("Digite a temperatura (em Celsius):");
 scanf("%f", &c);
 f = c * (9.0/5.0) + 32.0;
 printf("%.0f graus Celsius correspondem a %.0f Fahrenheit\n", c,f); 

 return 0;
}