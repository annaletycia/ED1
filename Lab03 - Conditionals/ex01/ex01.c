#include <stdio.h>

int main(){

  float p1, p2, p3, media;
  char letra;

  printf("<<Calculo da media>>\n");
  printf("Digite a inicial do nome do aluno: ");
  setbuf(stdin, NULL);
  scanf("%c", &letra);
  printf("Digite a nota da prova 1: ");
  scanf("%f", &p1);
  printf("Digite a nota da prova 2: ");
  scanf("%f", &p2);
  printf("Digite a nota da prova 3: ");
  scanf("%f", &p3);
  media = ((p1*1)+(p2*1)+(p3*2))/(1+1+2);

  if (media>=60.0){
  printf("A nota media do aluno %c. eh %.0f => APROVADO!\n", letra, media);
  }

  else{
    printf("A nota media do aluno %c. eh %.0f => REPROVADO!\n", letra, media);
  }

  return 0;
}