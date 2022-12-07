#include <stdio.h>

int main(){

  int num;

  printf("<<Contagem Progressiva ate o zero>>\n");
  printf("Qual eh o numero inicial? ");
  scanf("%d", &num);

  while(num<=0){
    printf("%d..", num);
    num++;
  }
  printf("FIM!");

  return 0;
}