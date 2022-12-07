#include <stdio.h>

int main(){

  int i=10;

  printf("<<Contagem Regressiva>>\n");

  while(i>=0){
    printf("%d..", i);
    i--;
  }
  printf("FIM!");

  return 0;
}