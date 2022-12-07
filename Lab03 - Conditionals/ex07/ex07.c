#include <stdio.h>
#include <math.h>

int main(){

 float A,B,C;

 printf("<<Tipo de Triangulo>>\n");
 printf("Digite o comprimento do lado 1:");
 scanf("%f", &A);
 printf("Digite o comprimento do lado 2:");
 scanf("%f", &B);
 printf("Digite o comprimento do lado 3:");
 scanf("%f", &C);

 if(A<0||B<0||C<0){
   printf("ERRO!\n");
 }
 else{
 
    if(A>B+C||B>A+C||C>A+B){
   printf("Nao eh possivel formar um triangulo\n");
 }
    if(pow(A,2)==pow(B,2)+pow(C,2)){
   printf("Triangulo Retangulo\n");
 }
    if(pow(A,2)>pow(B,2)+pow(C,2)){
   printf("Triangulo Obtusangulo\n");
 }
    if(pow(A,2)<pow(B,2)+pow(C,2)){
   printf("Triangulo Acutangulo\n");
 }
 }

 return 0;
}