#include <stdio.h>

int main(){

 float n1, n2, n3, maiorN, menorN;
 char a1, a2, a3, melhorA, piorA;

    printf("<<Notas da turma>>\n");
    printf("Digite a inicial do aluno #1: ");
    setbuf(stdin, NULL); 
    scanf("%c", &a1);
    printf("Digite a nota do aluno #1: ");
    scanf("%f", &n1);
    printf("Digite a inicial do aluno #2: ");
    setbuf(stdin, NULL); 
    scanf("%c", &a2);
    printf("Digite a nota do aluno #2: ");
    scanf("%f", &n2);
    printf("Digite a inicial do aluno #3: ");
    setbuf(stdin, NULL); 
    scanf("%c", &a3);
    printf("Digite a nota do aluno #3: ");
    scanf("%f", &n3);

      if (n1>n2 && n1>n3){
        maiorN = n1;
        melhorA = a1;
      }
      if (n2>n1 && n2>n3){
        maiorN = n2;
        melhorA = a2;
      }
      if (n3>n2 && n3>n1){
        maiorN = n3;
        melhorA = a3;
      }
      if (n1<n2 && n1<n3){
        menorN = n1;
        piorA = a1;
      }
      if (n2<n1 && n2<n3){
        menorN = n2;
        piorA = a2;
      }
      if (n3<n2 && n3<n1){
        menorN = n3;
        piorA = a3;
      }

    printf("%c. tem a maior nota (%.1f) e %c. tem a menor nota (%.1f)\n", melhorA, maiorN, piorA, menorN);

 return 0;
}