#include <stdio.h>

int main() {

    float p1, p2, media;
    char InicialNome;

    printf("<< Calculo da Media >>\n");
    printf("Digite a incial do nome do aluno: ");
    setbuf(stdin, NULL);
    scanf("%c", &InicialNome);
    printf("Digite a n0ota da prova 1: ");
    scanf("%f", &p1);
    printf("Digite a nota da prova 2: ");
    scanf("%f", &p2);
    media = (p1+p2)/2.0;
    printf("A nota media do aluno %c. eh %.1f\n", InicialNome, media);

  return 0;
}

/*
=> Altere o algoritmo anterior para que, antes de o usuário entrar com as 
notas do aluno ele entre com a inicial do nome do aluno. Ao final, 
mostrar a inicial do nome do aluno juntamente com a sua média.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Calculo da Media >>
Digite o nome do aluno: C
Digite a nota da prova 1: 70
Digite a nota da prova 2: 85
A nota media do aluno C. eh 77.5
-------------------------------------------------------------------------------
*/