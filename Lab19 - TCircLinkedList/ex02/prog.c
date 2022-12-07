//Uma das utilidades das listas circulares dinâmicas é a possibilidade de percorrer todos os elementos por diversas vezes em um loop. 
//Modifique o TAD para incluir uma função que retornará sempre o próximo elemento. Por exemplo, se a lista não foi percorrida ainda, o 
//próximo elemento é a cabeça. Depois, ao chamar a função novamente, será devolvido o segundo elemento, e assim sucessivamente. 
//Fique atento às funções de remoção, pois se um nó for removido ele não poderá ser mostrado.

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
    //printf("\nAlunos inseridos\n");

    //pop_front_circlist(clist);
    //printf("\nTamanho da fila: %d\n", circlist_size(clist));

    //print_circlist(clist);
    struct aluno al;
    circlist_prox(clist,&al);
    printf("\nO proximo aluno eh %s\n", al.nome);
    circlist_prox(clist,&al);
    printf("\nO proximo aluno eh %s\n", al.nome);
    circlist_prox(clist,&al);
    printf("\nO proximo aluno eh %s\n", al.nome);
    circlist_prox(clist,&al);
    printf("\nO proximo aluno eh %s\n", al.nome);

    circlist_free(clist);
    clist = NULL;
    return 0;
}