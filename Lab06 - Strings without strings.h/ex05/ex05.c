#include <stdio.h>

int main(){

int nome1[50], nome2[50];
char c,h;
int i=0,j=0, k=0;
int aux=0, pos=0;

  printf("<<Compara nomes>>\n");
  printf("Digite o nome 1: ");
  c = getchar();

  while (c != '\n') {
          nome1[pos] = c;
          pos++;
          c = getchar();
          }
  printf("Digite o nome 2: ");
  h = getchar();

  while (h != '\n') {
          nome2[aux] = h;
          aux++;
          h = getchar();
          }
    
    while(i<pos){
        while(j<aux){
            if(nome1[i] - nome2[j] == 0 || nome1[i] - nome2[j] == 32 || nome1[i] - nome2[j] == -32){
                i++;
                j++;
                k++;
            }else{
                printf("Os nomes digitados sao diferentes\n");
                k=0;
                break;
            }
        }
        break;
    }
    if(k>0){
    printf("Os nomes digitados sao iguais\n");
    }

return 0;
}

/*
Refaça o exercício anterior, para que agora não haja diferenciação entre caracteres maiúsculos e minúsculos.

Exemplo de saída:
<< Compara nomes>>
Digite o nome 1: Bruno
Digite o nome 2: BrunO
Os nomes digitados são iguais

<< Compara nomes>>
Digite o nome 1: Bruno
Digite o nome 2: Carlos
Os nomes digitados são diferentes
*/