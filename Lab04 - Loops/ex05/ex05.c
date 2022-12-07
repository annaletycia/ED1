#include <stdio.h>

int main(){

  int num;

  printf("<<Contagem Regressiva>>\n");
  printf("Qual eh o numero inicial? ");
  scanf("%d", &num);

  do{
    printf("%d..", num);
    num--;
  }while(num>=0);
  
  printf("FIM!");

  return 0;
}