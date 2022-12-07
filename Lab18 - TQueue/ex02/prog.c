#include <stdio.h>
#include <string.h>
#include "TQueue.h"

int main()
{   
    struct aluno a, b, c ,d;
    strcpy(a.nome,"Joao");
    a.matricula = 1;
    a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

    strcpy(b.nome,"Maria");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

    strcpy(c.nome,"Jose");
    c.matricula = 3;
    c.n1 = 0;    c.n2 = 0;    c.n3 = 4;

    strcpy(d.nome,"Ana");
    d.matricula = 4;
    d.n1 = 0;    d.n2 = 0;    d.n3 = 2;

    TQueue *queue;
    queue = queue_create();
    printf("\nQueue criada\n");

    queue_push(queue, a);
    queue_push(queue, b);
    queue_push(queue, c);
    queue_push(queue, d);
    printf("\nAlunos inseridos\n");
    queue_print(queue);

    printf("\nRemovendo aluno que esta na fila a mais tempo...\n");
    queue_pop(queue);
    printf("\nTamanho da fila: %d\n", queue_size(queue));

    struct aluno al;
    queue_front(queue,&al);
    printf("\nO aluno do topo eh %s\n", al.nome);

    queue_free(queue);
    queue = NULL;
    return 0;
}