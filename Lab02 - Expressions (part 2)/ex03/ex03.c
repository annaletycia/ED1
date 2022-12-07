#include <stdio.h>

int main(){

  float p1, p2, p3, media;
  char InicialNome;

  printf("<<Calculo da media ponderada>>\n");
  printf("Digite a inicial do nome do aluno: ");
  setbuf(stdin, NULL);
  scanf("%c", &InicialNome);
  printf("Digite a nota da prova 1: ");
  scanf("%f", &p1);
  printf("Digite a nota da prova 2: ");
  scanf("%f", &p2);
  printf("Digite a nota da prova 3: ");
  scanf("%f", &p3);
  media = ((p1*1)+(p2*1)+(p3*2))/(1+1+2);
  printf("A nota media do aluno %c. eh %.0f\n", InicialNome, media);

  return 0;
}

/*
=> Faça um algoritmo que calcule a média ponderada das notas de 3 provas. 
A primeira e a segunda prova têm peso 1 e a terceira tem peso 2. Antes de o usuário 
entrar com as notas do aluno ele deve informar a letra inicial do nome do aluno. 
Ao final, mostrar o a letra inicial do nome do aluno juntamente com a sua média.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Calculo da Media >>
Digite o nome do aluno: T
Digite a nota da prova 1: 40
Digite a nota da prova 2: 40
Digite a nota da prova 3: 80
A nota media do aluno T. eh 60
-------------------------------------------------------------------------------
*/