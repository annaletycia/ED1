#include <stdio.h>

int main(){

  int num;

  printf("<<Contagem Progressiva ate o zero>>\n");
  printf("Qual eh o numero inicial? ");
  scanf("%d", &num);

  do{
    printf("%d..", num);
    num++;
  }while(num<=0);

  printf("FIM!");

//O do-while nao eh a melhor estrutura para resolver este exercicio, pois a condiçao que controla o laço so eh testada no final do comando, executando as instruçoes no minimo uma vez antes de ver se a condiçao eh ou nao falsa.
  
  return 0;
}