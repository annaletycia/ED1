#include <stdio.h>
#include <string.h>
#include "TCircLinkedList.h"

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

    CircList *clist;
    clist = circlist_create();
    printf("\nLista circular criada\n");

    push_front_circlist(clist, a);
    push_front_circlist(clist, b);
    push_front_circlist(clist, c);
    insert_circlist(clist, 2,d);
    printf("\nAlunos inseridos\n");

    pop_front_circlist(clist);
    //printf("\nTamanho da fila: %d\n", circlist_size(clist));

    print_circlist(clist);
    struct aluno al;
    circlist_front(clist,&al);
    printf("\nO aluno do topo eh %s\n", al.nome);

    circlist_free(clist);
    clist = NULL;
    return 0;
}