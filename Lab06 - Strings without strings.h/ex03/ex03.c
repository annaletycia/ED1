#include <stdio.h>

int main(){

int nome[50];
char c;
int i, pos;
pos = 0;

  printf("<<Vetor de char>>\n");
  printf("Digite um nome: ");
  c = getchar();

  while (c != '\n') {
          nome[pos] = c;
          pos++;
          c = getchar();
          }
          printf("O nome digitado eh: ");
          for (i=0; i < pos; i++){
            if(nome[i]>96){
            printf("%c", nome[i]-32);
            }
            else{
              printf("%c", nome[i]);
            }
          }
return 0;
}

/*
Faça um programa semelhante ao anterior, só que o nome digitado deve ser mostrado 
em letras maiúsculas (pense como fazer isso olhando a diferença entre os valores 
dos caracteres minúsculos e maiúsculos na tabela ASCII). Não usar as funções de string.h

Exemplo de saída:
<< Vetor de char>>
Digite um nome: Bruno
O nome digitado é: BRUNO
*/