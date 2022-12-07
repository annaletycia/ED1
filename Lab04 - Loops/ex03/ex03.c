#include <stdio.h>

int main(){

  int i;

  printf("<<Contagem Regressiva>>\n");

  for(i=10; i>=0; i--){
    printf("%d..", i);
  }

  printf("FIM!");

  return 0;
}