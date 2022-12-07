#include <stdio.h>
#include <math.h>

int main(){

  char x, letra = 'y';
  int i, chances;

  printf("<<Forca de uma letra so>>\n");

  for(i=1; i<=5; i++){
    
    setbuf(stdin,NULL);
    printf("Qual a letra? ");scanf("%c", &x);
    chances = 5-i;

      if(x== letra){
        printf("ACERTOU!\n\n");
        break;
      }
      else{
        if(chances > 1){
        printf("Errado! Voce tem mais %d chances\n\n", chances);
        }
        if(chances == 1){
          printf("Errado! Ultima chance!\n\n");
        }
        if(chances == 0){
          printf("Acabaram suas chances. A letra correta eh '%c'\n\n", letra);
          break;
        }
      }
  }
  

  return 0;
}