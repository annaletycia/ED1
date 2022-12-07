#include <stdio.h>

int main(){

  int num;

  printf("<<Contagem Regressiva>>\n");
  printf("Qual eh o numero inicial? ");
  scanf("%d", &num);

  for(num=num; num>=0; num--){
    printf("%d..", num);
  }
  printf("FIM!");

  return 0;
}