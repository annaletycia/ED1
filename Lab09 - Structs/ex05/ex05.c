#include <stdio.h>
#include <string.h>

typedef struct aluno{

    int matricula, faltas;
    float p1,p2,p3,media;
    char nome[50];

    }Aluno;

int main(){

//(a)
    Aluno a[3];

    for(int i; i<3; i++){

        printf("Entre com os dados do aluno (%d):\n", i+1);
        printf("Matricula: ");
        scanf("%d", &a[i].matricula);
        printf("Nome: ");
        scanf("%s", a[i].nome);
        printf("Nota da prova 1: ");
        scanf("%f", &a[i].p1);
        printf("Nota da prova 2: ");
        scanf("%f", &a[i].p2);
        printf("Nota da prova 3: ");
        scanf("%f", &a[i].p3);
        printf("Numero de faltas: ");
        scanf("%d", &a[i].faltas);
        printf("\n");
    }

//(b)
    float maiorN = a[0].p1;
    char nomeN[50];

        for(int i=1; i<3; i++){
            if(a[i].p1 > maiorN){
                maiorN = a[i].p1;
                strcpy(nomeN, a[i].nome); 
            }
        }
        printf("\nAluno com maior nota na prova 1 foi %s com %.1f pontos.",nomeN, maiorN);

//(c)
    for(int i=0; i<3; i++){

        a[i].media = (a[i].p1 + a[i].p2 + a[i].p3)/3.0;
    }

    float maiorMG = a[0].media;
    char nomeMG[50];

    for(int i=1; i<3; i++){

        if(a[i].media > maiorMG){
                maiorMG = a[i].media;
                strcpy(nomeMG, a[i].nome); 
            }
    }
    printf("\nAluno com maior media geral foi %s com %.1f pontos.", nomeMG, maiorMG);

//(d)
    float menorMG = a[0].media;
    char nomeMenor[50];

    for(int i=1; i<3; i++){

        if(a[i].media < maiorMG){
                menorMG = a[i].media;
                strcpy(nomeMenor, a[i].nome); 
            }
    }
    printf("\nAluno com menor media geral foi %s com %.1f pontos.\n", nomeMenor, menorMG);

//(e)
    printf("\nSituacao dos Alunos:\n");

    int j=1;

    for(int i=0; i<3; i++){

        if(a[i].media<60.0){
            printf("%d- %s. Reprovado por nota.\n", j, a[i].nome);
            j++;
        }
        else if(a[i].faltas>18){
            printf("%d- %s. Reprovado por falta.\n", j, a[i].nome);
            j++;
        }
        else{
            printf("%d- %s. Aprovado.\n", j, a[i].nome);
            j++;
        }

    }

    return 0;
}

/*
5.Crie uma estrutura representando os alunos de um curso de graduação. 
A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, 
nota da segunda prova, nota da terceira prova, média e número de faltas.

    (a) Permita ao usuário entrar com os dados de 3 alunos. 
    (b) Encontre o aluno com maior nota da primeira prova.
    (c) Encontre o aluno com maior média geral.
    (d) Encontre o aluno com menor média geral.
    (e) Mostre a situação final do aluno. Para ser aprovado o aluno precisa ter nota média final 
        maior ou igual a 60 e ter presença maior ou igual a 75% (considere um total de 72 aulas). 
        No caso de reprovação, mostrar o motivo da mesma, isto é, caso o aluno foi reprovado por 
        falta, mostrar “Reprovado por falta”. Caso tenha sido reprovado por nota, mostrar “Reprovado por nota”. 
        Se um aluno foi reprovado por falta e por nota, prevalece, como motivo para reprovação, as faltas. Assim,
        mostrar a mensagem “Reprovado por falta”. 


-------------------------------------------------------------------------------
Exemplo de saída:
Entre com os dados do 1º aluno: 
Matricula: 1
Nome: Paulo
Nota da prova 1: 50
Nota da prova 2: 70
Nota da prova 3: 60
Numero de faltas: 12

Entre com os dados do 2º aluno: 
Matricula: 2
Nome: Gustavo
Nota da prova 1: 95
Nota da prova 2: 90
Nota da prova 3: 100
Numero de faltas: 19

Entre com os dados do 3º aluno: 
Matricula: 3
Nome: Luis
Nota da prova 1: 50
Nota da prova 2: 60
Nota da prova 3: 58
Numero de faltas: 2

Aluno com maior nota na prova 1 foi Gustavo com 95,0 pontos.
Aluno com maior media geral foi Gustavo com 95,0 pontos.
Aluno com menor media geral foi Luis com 56,0 pontos.

Situacao dos Alunos: 
1- Paulo. Aprovado.
2- Gustavo. Reprovado por falta.
3- Luis. Reprovado por nota.
-------------------------------------------------------------------------------
*/