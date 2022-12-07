#include <stdio.h>

int main(){

  int i=10;

  printf("<<Contagem Regressiva>>\n");

  do{
    printf("%d..", i);
    i--;
  
  }while(i>=0);

  printf("FIM!");

  return 0;
}